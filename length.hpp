#pragma once

#include "unit.h"

class length {
private:
    const long long double rawValue;

public:
    length(long long double i, lengthTypes t);

    long long double toMillimeter();
    long long double toCentimeter();
    long long double toMeter();
    long long double toKilometer();
    long long double toInch();
    long long double toFeet();
    long long double toYard();
    long long double toMile();
};
