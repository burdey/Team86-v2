cmake_minimum_required(VERSION 3.19)
project(OOP_S1_2022_projectV01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_S1_2022_projectV01 main.cpp Test.h Test.cpp Address.cpp Capital.cpp )
