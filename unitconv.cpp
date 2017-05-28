#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

#include "zku.h"
#include "unit.h"
#include "unitutil.hpp"
#include "length.hpp"

using namespace std;

struct config {
    char *master;
    char *ident;
};

struct config *confs;
const char *unitConv(const char *req);
int confcnt = 0;
int confcap = 0;

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
        confs = (config *)calloc(confcap = 1, sizeof(struct config));
    else if (confcnt == confcap) {
        void *temp = realloc(confs, confcap *= 2);
        if (temp) {
            confs = (config *)temp;
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
    const char *funcResult = unitConv(req);
    if (funcResult == NULL)
        return NULL;

    char *res = (char *)malloc(256);
    *res = '\0';
    writemsg(res, "sender", conf->ident);
    writemsg(res, "type", ZKU_ZSMP);
    writemsg(res, "id", id);
    sprintf(id, "%ld", (long)time(NULL));
    writemsg(res, "timestamp", id);
    writemsg(res, "response", req);
    return res;
}

const char *unitConv(const char *req) {
    const string input = string(req);
    const string::size_type toLocation = input.find("to", 0);
    long long double numberInput = 0;
    long long double numberOutput = 0;

    if (toLocation != string::npos) // Maybe conversion?
    {
        string::size_type sz;
        try {
            numberInput = stod(input, &sz);
        }
        catch (...) {
            return NULL;
        }

        string firstString = input.substr(sz, toLocation);
        string secondString = input.substr(toLocation, string::npos);

        unitTypes firstUnitType = getUnitType(firstString);
        unitTypes secondUnitType = getUnitType(secondString);

        if (firstUnitType != secondUnitType)
            return NULL;

        switch (firstUnitType) {
            //TODO: Add multiple unit types
            case length:
                lengthTypes firstLengthType = getLengthType(firstString);
                length first(numberInput, firstLengthType);
                switch (firstLengthType) {
                    case millimeter:
                        numberOutput = first.toMillimeter();
                        break;
                    case centimeter:
                        numberOutput = first.toCentimeter();
                        break;
                    case meter:
                        numberOutput = first.toMeter();
                        break;
                    case kilometer:
                        numberOutput = first.toKilometer();
                        break;
                    case inch:
                        numberOutput = first.toInch();
                        break;
                    case feet:
                        numberOutput = first.toFeet();
                        break;
                    case yard:
                        numberOutput = first.toYard();
                        break;
                    case mile:
                        numberOutput = first.toMile();
                        break;
                    case notLength:
                        return NULL;
                }
                break;
            case notUnit:
                return NULL;
        }

        // Got numberOutput
        stringstream tempStream;
        tempStream << numberOutput;

        return to_string(numberOutput).data();
    }
    else {
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
