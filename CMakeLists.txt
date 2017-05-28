CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT(libzku_unitconv)

SET(CMAKE_CXX_STANDARD 11)

SET(SOURCE_FILES
    unitconv.cpp zku.h
    length.cpp length.hpp
    unit.h
    unitutil.cpp unitutil.hpp)

ADD_LIBRARY(libzku_unitconv SHARED ${SOURCE_FILES})