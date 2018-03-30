cmake_minimum_required(VERSION 3.9)
project(TIS2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -lpspdebugkb -fno-rtti -fexceptions -Wall -O2 -std=c++1y")

add_executable(TIS2 main.cpp pspcallbacks.hpp)
include_directories("/usr/local/pspdev/psp/sdk/include")