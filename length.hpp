#pragma once

#include "unit.h"

class length {
private:
    // raw value for lengthUnit is meter
    long double rawValue;

public:
    length(long double i, lengthTypes t);

    long double toMillimeter();
    long double toCentimeter();
    long double toMeter();
    long double toKilometer();
    long double toInch();
    long double toFeet();
    long double toYard();
    long double toMile();
};
