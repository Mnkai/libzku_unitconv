#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>

#include "zku.h"

using namespace std;

struct config {
    char *master;
    char *ident;
};

struct config *confs;
char *unitConv(const char *req);
int confcnt = 0;
int confcap = 0;

const vector<string> length = {};

const char *readmsg(char *key, char *value, const char *msg) {
    if (!*msg)
        return NULL;
    int escaping = 0;
    char *dest = key;
    int phase = 0;
    while (*msg) {
        if (escaping) {
            switch (*msg) {
                case 'a':
                    *dest++ = '\a';
                    escaping = 0;
                    break;
                case 'b':
                    *dest++ = '\b';
                    escaping = 0;
                    break;
                case 'f':
                    *dest++ = '\f';
                    escaping = 0;
                    break;
                case 'n':
                    *dest++ = '\n';
                    escaping = 0;
                    break;
                case 'r':
                    *dest++ = '\r';
                    escaping = 0;
                    break;
                case 't':
                    *dest++ = '\t';
                    escaping = 0;
                    break;
                case 'v':
                    *dest++ = '\v';
                    escaping = 0;
                    break;
                default:
                    *dest++ = *msg;
                    escaping = 0;
                    break;
            }
        }
        else if (*msg == '\\')
            escaping = 1;
        else if (phase == 0 && *msg == '=') {
            *dest = '\0';
            dest = value;
            phase++;
        }
        else if (phase == 1 && *msg == '\n') {
            *dest = '\0';
            break;
        }
        else
            *dest++ = *msg;
        msg++;
    }
    return ++msg;
}

void writemsg(char *msg, const char *key, const char *value) {
    msg += strlen(msg);
    const char *src = key;
    int phase = 0;
    while (1) {
        switch (*src) {
            case '=':
            case '\\':
                *msg++ = '\\';
                *msg++ = *src;
                break;
            case '\a':
                *msg++ = '\\';
                *msg++ = 'a';
                break;
            case '\b':
                *msg++ = '\\';
                *msg++ = 'b';
                break;
            case '\f':
                *msg++ = '\\';
                *msg++ = 'f';
                break;
            case '\n':
                *msg++ = '\\';
                *msg++ = 'n';
                break;
            case '\r':
                *msg++ = '\\';
                *msg++ = 'r';
                break;
            case '\t':
                *msg++ = '\\';
                *msg++ = 't';
                break;
            case '\v':
                *msg++ = '\\';
                *msg++ = 'v';
                break;
            case '\0':
                if (phase == 0) {
                    *msg++ = '=';
                    src = value - 1;
                    phase++;
                }
                else {
                    *msg++ = '\n';
                    phase++;
                }
                break;
            default:
                if (*src >= ' ')
                    *msg++ = *src;
                break;
        }
        if (phase == 2)
            break;
        src++;
    }
    *msg = '\0';
}

int load(const char *msg, long size) {
    if (confcap == 0)
        confs = (config *) calloc(confcap = 1, sizeof(struct config));
    else if (confcnt == confcap) {
        void *temp = realloc(confs, confcap *= 2);
        if (temp) {
            confs = (config *) temp;
            memset(confs + confcnt, 0, sizeof(struct config) * confcnt);
        }
    }
    struct config *conf = &confs[confcnt++];
    char key[256];
    char value[2048];
    while ((msg = readmsg(key, value, msg))) {
        if (strcmp(key, "sender") == 0)
            conf->master = strdup(value);
        else if (strcmp(key, "ident") == 0)
            conf->ident = strdup(value);
    }
    if (conf->master && conf->ident)
        return 0;
    return 1;
}

void *execute(const char *msg, long size) {
    const char *req = msg;
    char key[256];
    char value[2048];
    char sender[512] = {0};
    char id[12] = {0};
    while ((msg = readmsg(key, value, msg))) {
        if (strcmp(key, "sender") == 0)
            strcpy(sender, value);
        else if (strcmp(key, "id") == 0)
            strcpy(id, value);
    }
    struct config *conf = NULL;
    for (int i = 0; i < confcap; i++)
        if (strcmp(confs[i].master, sender) == 0) {
            conf = &confs[i];
            break;
        }
    if (!conf)
        return NULL;

    // Do work
    char *funcResult = unitConv(req);

    char *res = (char*) malloc(256);
    *res = '\0';
    writemsg(res, "sender", conf->ident);
    writemsg(res, "type", ZKU_ZSMP);
    writemsg(res, "id", id);
    sprintf(id, "%ld", (long)time(NULL));
    writemsg(res, "timestamp", id);
    writemsg(res, "response", req);
    return res;
}

char *unitConv(const char *req) {
    string input = string(req);

    if ( input.find("to", 0) != string::npos ) // Maybe conversion?
    {
        // Do work
    }
    else
    {
        return NULL;
    }
}

int unload(const char *msg, long size) {
    char key[256];
    char value[2048];
    char sender[512] = {0};
    while ((msg = readmsg(key, value, msg))) {
        if (strcmp(key, "sender"))
            strcpy(sender, value);
    }
    struct config *conf = NULL;
    for (int i = 0; i < confcap; i++)
        if (strcmp(confs[i].master, sender)) {
            conf = &confs[i];
            free(conf->master);
            free(conf->ident);
            memset(conf, 0, sizeof(struct config));
            break;
        }
    if (conf)
        return 0;
    return 1;
}
