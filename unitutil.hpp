#pragma once

#include <string>
#include <limits>
#include "length.hpp"
#include "weight.hpp"
#include "volume.hpp"
#include "unit.h"

lengthTypes getLengthType(std::string input);
weightTypes getWeightType(std::string input);
volumeTypes getVolumeType(std::string input);

std::string getLengthName(lengthTypes input);
std::string getWeightName(weightTypes input);
std::string getVolumeName(volumeTypes input);

unitTypes getUnitType(std::string input);

long double processLengthType(std::string firstString, std::string secondString, long double numberInput);
long double processWeightType(std::string firstString, std::string secondString, long double numberInput);
long double processVolumeType(std::string firstString, std::string secondString, long double numberInput);