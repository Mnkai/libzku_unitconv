CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT(libzku_unitconv)

SET(CMAKE_CXX_STANDARD 11)

SET(SOURCE_FILES
    unitconv.cpp zku.h
    length.cpp length.hpp
    weight.cpp weight.hpp
    volume.cpp volume.hpp
    unit.h
    util.cpp
    unitutil.cpp unitutil.hpp)

ADD_LIBRARY(zku_unitconv SHARED ${SOURCE_FILES})