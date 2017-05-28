#include "unit.h"

class length {
private:
    // raw value for length is millimeter
    const long long double rawValue;

public:
    length(double i, lengthTypes t) {
        // TODO: Get original length type, and convert to millimeter, and save
        switch (lengthTypes)
        {
            case millimeter:

                break;
            case centimeter:

                break;
            case meter:

                break;
            case kilometer:

                break;
            case inch:

                break;
            case feet:

                break;
            case yard:

                break;
        }

        rawValue = i;
    }

    long long double toMillimeter(){return rawValue;}
    long long double toCentimeter(){return 10*rawValue;}
    long long double toMeter(){return 100*10*rawValue;}
    long long double toKilometer(){return 1000*10*rawValue;}
    long long double toInch(){return 0.0393701*rawValue;}
    long long double toFeet(){return 0.00328084*rawValue;}
    long long double toYard(){return 0.00109361*rawValue;}
};
