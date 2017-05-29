#include "unitutil.hpp"

lengthTypes getLengthType(std::string input) {
    if (input.find("mm") != std::string::npos ||
        input.find("millimeter") != std::string::npos ||
        input.find("millimetre") != std::string::npos)
        return millimeter;
    else if (input.find("cm") != std::string::npos ||
             input.find("centimeter") != std::string::npos ||
             input.find("centimetre") != std::string::npos)
        return centimeter;
    else if (input.find("km") != std::string::npos ||
             input.find("kilometer") != std::string::npos ||
             input.find("kilometre") != std::string::npos)
        return kilometer;
    else if (input.find("mi") != std::string::npos ||
             input.find("mile") != std::string::npos)
        return mile;
    else if (input.find("m") != std::string::npos ||
             input.find("meter") != std::string::npos ||
             input.find("metre") != std::string::npos)
        return meter;
    else if (input.find("in") != std::string::npos ||
             input.find("inch") != std::string::npos)
        return inch;
    else if (input.find("ft") != std::string::npos ||
             input.find("feet") != std::string::npos)
        return feet;
    else if (input.find("yd") != std::string::npos ||
             input.find("yard") != std::string::npos)
        return yard;
    else
        return notLength;
}

weightTypes getWeightType(std::string input) {
    if (input.find("mg") != std::string::npos ||
        input.find("milligram") != std::string::npos)
        return milligram;
    else if (input.find("kg") != std::string::npos ||
             input.find("kilogram") != std::string::npos)
        return kilogram;
    else if (input.find("kt") != std::string::npos ||
             input.find("kiloton") != std::string::npos)
        return kiloton;
    else if (input.find("t") != std::string::npos ||
             input.find("ton") != std::string::npos)
        return ton;
    else if (input.find("gr") != std::string::npos ||
             input.find("grain") != std::string::npos)
        return grain;
    else if (input.find("g") != std::string::npos ||
             input.find("gram") != std::string::npos)
        return gram;
    else if (input.find("oz") != std::string::npos ||
             input.find("ounce") != std::string::npos)
        return ounce;
    else if (input.find("lb") != std::string::npos ||
             input.find("pound") != std::string::npos)
        return pound;
    else
        return notWeight;
}

volumeTypes getVolumeType(std::string input) {

    if (input.find("cm^3") != std::string::npos ||
        input.find("cubic centimeter") != std::string::npos ||
        input.find("cubic centimetre") != std::string::npos)
        return cubiccentimeter;
    else if (input.find("m^3") != std::string::npos ||
             input.find("cubic meter") != std::string::npos ||
             input.find("cubic metre") != std::string::npos)
        return cubicmeter;
    else if (input.find("gal") != std::string::npos ||
             input.find("gallon") != std::string::npos)
        return gallon;
    else if (input.find("pt") != std::string::npos ||
             input.find("pint") != std::string::npos)
        return pint;
    else if (input.find("gill") != std::string::npos)
        return gill;
    else if (input.find("qt") != std::string::npos ||
             input.find("quart") != std::string::npos)
        return quart;
    else if (input.find("l") != std::string::npos ||
             input.find("liter") != std::string::npos ||
             input.find("litre") != std::string::npos)
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