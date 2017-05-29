#include "weight.hpp"

weight::weight(long double i, weightTypes t) {
    switch (t) {
        case milligram:
            rawValue = 0.001 * i;
            break;
        case gram:
            rawValue = i;
            break;
        case kilogram:
            rawValue = 1000 * i;
            break;
        case ton:
            rawValue = 1000000 * i;
            break;
        case kiloton:
            rawValue = 1000000000 * i;
            break;
        case grain:
            rawValue = 0.0647989 * i;
            break;
        case ounce:
            rawValue = 28.3495 * i;
            break;
        case pound:
            rawValue = 453.592 * i;
            break;
        case notWeight:
            break;
    }
}

long double weight::toMilliGram() {
    return 1000 * rawValue;
}

long double weight::toGram() {
    return rawValue;
}

long double weight::toKiloGram() {
    return 0.001 * rawValue;
}

long double weight::toTon() {
    return 0.000001 * rawValue;
}

long double weight::toKiloTon() {
    return 0.000000001 * rawValue;
}

long double weight::toGrain() {
    return 15.4324 * rawValue;
}

long double weight::toOunce() {
    return 0.035274 * rawValue;
}

long double weight::toPound() {
    return 0.00220462 * rawValue;
}

