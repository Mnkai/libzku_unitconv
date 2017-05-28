#include "unit.h"
#include "unitutil.hpp"
#include <string>

lengthTypes getLengthType(std::string input) {
    if (input.find("mm") != string::npos || input.find("millimeter") != string::npos ||
        input.find("millimetre") != string::npos)
        return millimeter;
    else if (input.find("cm") != string::npos || input.find("centimeter") != string::npos ||
             input.find("centimetre") != string::npos)
        return centimeter;
    else if (input.find("km") != string::npos || input.find("kilometer") != string::npos ||
             input.find("kilometre") != string::npos)
        return kilometer;
    else if (input.find("m") != string::npos || input.find("meter") != string::npos ||
             input.find("metre") != string::npos)
        return meter;
    else if (input.find("in") != string::npos || input.find("inch") != string::npos)
        return inch;
    else if (input.find("ft") != string::npos || input.find("feet") != string::npos)
        return feet;
    else if (input.find("yd") != string::npos || input.find("yard") != string::npos)
        return yard;
    else if (input.find("mi") != string::npos || input.find("mile") != string::npos)
        return mile;
    else
        return notLength;
}

unitTypes getUnitType(std::string input) {
    //TODO: Detect multiple units

    lengthTypes isLength = getLengthType(input);
    if (isLength != notLength)
        return length;

    else
        return notUnit;
}