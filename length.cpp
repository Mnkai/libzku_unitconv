#include "unit.h"

class length {
private:
    // raw value for length is meter
    const long long double rawValue;

public:
    length(long long double i, lengthTypes t) {
        switch (lengthTypes)
        {
            case millimeter:
                rawValue = 0.001*i;
                break;
            case centimeter:
                rawValue = 0.01i;
                break;
            case meter:
                rawValue = i;
                break;
            case kilometer:
                rawValue = 1000*i;
                break;
            case inch:
                rawValue = 0.0254*i;
                break;
            case feet:
                rawValue = 0.3048*i;
                break;
            case yard:
                rawValue = 0.9144*i;
                break;
            case mile:
                rawValue = 1609.34*i;
                break;
        }

        rawValue = i;
    }

    long long double toMillimeter(){return 1000*rawValue;}
    long long double toCentimeter(){return 100*rawValue;}
    long long double toMeter(){return rawValue;}
    long long double toKilometer(){return 0.001*rawValue;}
    long long double toInch(){return 39.3701*rawValue;}
    long long double toFeet(){return 3.28084*rawValue;}
    long long double toYard(){return 1.09361*rawValue;}
    long long double toMile(){return 0.000621371*rawValue;}
};
