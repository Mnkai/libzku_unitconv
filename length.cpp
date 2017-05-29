#include "length.hpp"

length::length(long double i, lengthTypes t) {
    switch (t) {
        case millimeter:
            rawValue = 0.001 * i;
            break;
        case centimeter:
            rawValue = 0.01 * i;
            break;
        case meter:
            rawValue = i;
            break;
        case kilometer:
            rawValue = 1000 * i;
            break;
        case inch:
            rawValue = 0.0254 * i;
            break;
        case feet:
            rawValue = 0.3048 * i;
            break;
        case yard:
            rawValue = 0.9144 * i;
            break;
        case mile:
            rawValue = 1609.34 * i;
            break;
        case notLength:
            break;
    }
}

long double length::toMilliMeter() {
    return 1000 * rawValue;
}

long double length::toCentiMeter() {
    return 100 * rawValue;
}

long double length::toMeter() {
    return rawValue;
}

long double length::toKiloMeter() {
    return 0.001 * rawValue;
}

long double length::toInch() {
    return 39.3701 * rawValue;
}

long double length::toFeet() {
    return 3.28084 * rawValue;
}

long double length::toYard() {
    return 1.09361 * rawValue;
}

long double length::toMile() {
    return 0.000621371 * rawValue;
}

