#pragma once

#include "unit.h"

class weight {
private:
    // raw value for weightUnit is gram
    long double rawValue;

public:
    weight(long double i, weightTypes t);

    long double toMilliGram();
    long double toGram();
    long double toKiloGram();

    // We use metric ton
    long double toTon();
    long double toKiloTon();

    long double toGrain();
    long double toOunce();
    long double toPound();
};
