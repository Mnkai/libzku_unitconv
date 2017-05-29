#pragma once

#include "unit.h"

class volume {
private:
    // raw value for volumeUnit is cubic meter
    long double rawValue;

public:
    volume(long double i, volumeTypes t);

    long double toCubicMeter();
    long double toCubicCentiMeter();
    long double toLiter();

    // US Liquid Gallon
    long double toGallon();
    // US Liquid Pint
    long double toPint();
    // US Gill
    long double toGill();
    // US Liquid Quart
    long double toQuart();
};
