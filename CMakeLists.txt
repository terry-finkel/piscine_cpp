cmake_minimum_required(VERSION 3.13)
project(piscine_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Day00)
include_directories(Day01)
include_directories(Day02)
include_directories(Day03)
include_directories(Day04)
include_directories(Day05)
include_directories(Day06)
include_directories(Day07)
include_directories(Day08)

add_executable(piscine_cpp
        Day00/ex00/megaphone.cpp
        Day00/ex01/Contact.hpp
        Day00/ex01/Contact.cpp
        Day00/ex01/phonebook.cpp)
