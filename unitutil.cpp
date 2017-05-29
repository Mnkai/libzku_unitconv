#include "unitutil.hpp"

lengthTypes getLengthType(std::string input) {
    if (input.compare("mm") == 0 ||
        input.compare("millimeter") == 0 ||
        input.compare("millimetre") == 0)
        return millimeter;
    else if (input.compare("cm") == 0 ||
             input.compare("centimeter") == 0 ||
             input.compare("centimetre") == 0)
        return centimeter;
    else if (input.compare("km") == 0 ||
             input.compare("kilometer") == 0 ||
             input.compare("kilometre") == 0)
        return kilometer;
    else if (input.compare("mi") == 0 ||
             input.compare("mile") == 0)
        return mile;
    else if (input.compare("m") == 0 ||
             input.compare("meter") == 0 ||
             input.compare("metre") == 0)
        return meter;
    else if (input.compare("in") == 0 ||
             input.compare("inch") == 0)
        return inch;
    else if (input.compare("ft") == 0 ||
             input.compare("feet") == 0)
        return feet;
    else if (input.compare("yd") == 0 ||
             input.compare("yard") == 0)
        return yard;
    else
        return notLength;
}

weightTypes getWeightType(std::string input) {
    if (input.compare("mg") == 0 ||
        input.compare("milligram") == 0)
        return milligram;
    else if (input.compare("kg") == 0 ||
             input.compare("kilogram") == 0)
        return kilogram;
    else if (input.compare("kt") == 0 ||
             input.compare("kiloton") == 0)
        return kiloton;
    else if (input.compare("t") == 0 ||
             input.compare("ton") == 0)
        return ton;
    else if (input.compare("gr") == 0 ||
             input.compare("grain") == 0)
        return grain;
    else if (input.compare("g") == 0 ||
             input.compare("gram") == 0)
        return gram;
    else if (input.compare("oz") == 0 ||
             input.compare("ounce") == 0)
        return ounce;
    else if (input.compare("lb") == 0 ||
             input.compare("pound") == 0)
        return pound;
    else
        return notWeight;
}

volumeTypes getVolumeType(std::string input) {

    if (input.compare("cm^3") == 0 ||
        input.compare("cubic centimeter") == 0 ||
        input.compare("cubic centimetre") == 0)
        return cubiccentimeter;
    else if (input.compare("m^3") == 0 ||
             input.compare("cubic meter") == 0 ||
             input.compare("cubic metre") == 0)
        return cubicmeter;
    else if (input.compare("gal") == 0 ||
             input.compare("gallon") == 0)
        return gallon;
    else if (input.compare("pt") == 0 ||
             input.compare("pint") == 0)
        return pint;
    else if (input.compare("gill") == 0)
        return gill;
    else if (input.compare("qt") == 0 ||
             input.compare("quart") == 0)
        return quart;
    else if (input.compare("l") == 0 ||
             input.compare("liter") == 0 ||
             input.compare("litre") == 0)
        return liter;
    else
        return notVolume;
}

std::string getLengthName(lengthTypes input) {
    switch (input) {
        case millimeter:
            return "mm";
        case centimeter:
            return "cm";
        case meter:
            return "m";
        case kilometer:
            return "km";
        case inch:
            return "in";
        case feet:
            return "ft";
        case yard:
            return "yd";
        case mile:
            return "mi";
        case notLength:
            return NULL;
    }
}

std::string getWeightName(weightTypes input) {
    switch (input) {
        case milligram:
            return "mg";
        case gram:
            return "g";
        case kilogram:
            return "kg";
        case ton:
            return "t (Metric)";
        case kiloton:
            return "kt";
        case grain:
            return "gr";
        case ounce:
            return "oz";
        case pound:
            return "lb";
        case notWeight:
            return NULL;
    }
}

std::string getVolumeName(volumeTypes input) {
    switch (input) {
        case cubicmeter:
            return "m^3";
        case cubiccentimeter:
            return "cm^3";
        case liter:
            return "l";
        case gallon:
            return "gal (US liquid)";
        case pint:
            return "pt (US liquid)";
        case gill:
            return "gill (US)";
        case quart:
            return "qt (US liquid)";
        case notVolume:
            return NULL;
    }
}

//TODO: Detect multiple units
unitTypes getUnitType(std::string input) {
    if (getLengthType(input) != notLength)
        return lengthUnit;
    else if (getWeightType(input) != notWeight)
        return weightUnit;
    else if (getVolumeType(input) != notVolume)
        return volumeUnit;
    else
        return notUnit;
}

long double processLengthType(std::string firstString, std::string secondString, long double numberInput) {
    long double toReturn = std::numeric_limits<long double>::min();

    lengthTypes firstLengthType = getLengthType(firstString);
    lengthTypes secondLengthType = getLengthType(secondString);
    length first = length(numberInput, firstLengthType);
    switch (secondLengthType) {
        case millimeter:
            toReturn = first.toMilliMeter();
            break;
        case centimeter:
            toReturn = first.toCentiMeter();
            break;
        case meter:
            toReturn = first.toMeter();
            break;
        case kilometer:
            toReturn = first.toKiloMeter();
            break;
        case inch:
            toReturn = first.toInch();
            break;
        case feet:
            toReturn = first.toFeet();
            break;
        case yard:
            toReturn = first.toYard();
            break;
        case mile:
            toReturn = first.toMile();
            break;
        case notLength:
            toReturn = std::numeric_limits<long double>::min();
            break;
    }

    return toReturn;
}

long double processWeightType(std::string firstString, std::string secondString, long double numberInput) {
    long double toReturn = std::numeric_limits<long double>::min();

    weightTypes firstWeightType = getWeightType(firstString);
    weightTypes secondWeightType = getWeightType(secondString);
    weight first = weight(numberInput, firstWeightType);
    switch (secondWeightType) {
        case milligram:
            toReturn = first.toMilliGram();
            break;
        case gram:
            toReturn = first.toGram();
            break;
        case kilogram:
            toReturn = first.toKiloGram();
            break;
        case ton:
            toReturn = first.toTon();
            break;
        case kiloton:
            toReturn = first.toKiloTon();
            break;
        case grain:
            toReturn = first.toGrain();
            break;
        case ounce:
            toReturn = first.toOunce();
            break;
        case pound:
            toReturn = first.toPound();
            break;
        case notWeight:
            toReturn = std::numeric_limits<long double>::min();
            break;
    }

    return toReturn;
}

long double processVolumeType(std::string firstString, std::string secondString, long double numberInput) {
    long double toReturn = std::numeric_limits<long double>::min();

    volumeTypes firstVolumeType = getVolumeType(firstString);
    volumeTypes secondVolumeType = getVolumeType(secondString);
    volume first = volume(numberInput, firstVolumeType);
    switch (secondVolumeType) {
        case cubicmeter:
            toReturn = first.toCubicMeter();
            break;
        case cubiccentimeter:
            toReturn = first.toCubicCentiMeter();
            break;
        case liter:
            toReturn = first.toLiter();
            break;
        case gallon:
            toReturn = first.toGallon();
            break;
        case pint:
            toReturn = first.toPint();
            break;
        case gill:
            toReturn = first.toGill();
            break;
        case quart:
            toReturn = first.toQuart();
            break;
        case notVolume:
            toReturn = std::numeric_limits<long double>::min();
            break;
    }

    return toReturn;
}