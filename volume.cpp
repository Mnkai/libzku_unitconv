#include "volume.hpp"

volume::volume(long double i, volumeTypes t) {
    switch (t) {
        case cubicmeter:
            rawValue = i;
            break;
        case cubiccentimeter:
            rawValue = 0.000001 * i;
            break;
        case liter:
            rawValue = 0.001 * i;
            break;
        case gallon:
            rawValue = 0.00378541 * i;
            break;
        case pint:
            rawValue = 0.000473176 * i;
            break;
        case gill:
            rawValue = 0.000118294 * i;
            break;
        case quart:
            rawValue = 0.000946353 * i;
            break;
        case notVolume:
            break;
    }
}

long double volume::toCubicMeter() {
    return rawValue;
}

long double volume::toCubicCentiMeter() {
    return 1000000 * rawValue;
}

long double volume::toLiter() {
    return 1000 * rawValue;
}

long double volume::toGallon() {
    return 264.172 * rawValue;
}

long double volume::toPint() {
    return 2113.38 * rawValue;
}

long double volume::toGill() {
    return 8453.51 * rawValue;
}

long double volume::toQuart() {
    return 1056.69 * rawValue;
}



