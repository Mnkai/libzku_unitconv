#include "unitutil.hpp"

lengthTypes getLengthType(std::string input) {
    if (input.find("mm") != std::string::npos || input.find("millimeter") != std::string::npos ||
        input.find("millimetre") != std::string::npos)
        return millimeter;
    else if (input.find("cm") != std::string::npos || input.find("centimeter") != std::string::npos ||
             input.find("centimetre") != std::string::npos)
        return centimeter;
    else if (input.find("km") != std::string::npos || input.find("kilometer") != std::string::npos ||
             input.find("kilometre") != std::string::npos)
        return kilometer;
    else if (input.find("m") != std::string::npos || input.find("meter") != std::string::npos ||
             input.find("metre") != std::string::npos)
        return meter;
    else if (input.find("in") != std::string::npos || input.find("inch") != std::string::npos)
        return inch;
    else if (input.find("ft") != std::string::npos || input.find("feet") != std::string::npos)
        return feet;
    else if (input.find("yd") != std::string::npos || input.find("yard") != std::string::npos)
        return yard;
    else if (input.find("mi") != std::string::npos || input.find("mile") != std::string::npos)
        return mile;
    else
        return notLength;
}

unitTypes getUnitType(std::string input) {
    //TODO: Detect multiple units

    lengthTypes isLength = getLengthType(input);
    if (isLength != notLength)
        return lengthUnit;

    else
        return notUnit;
}