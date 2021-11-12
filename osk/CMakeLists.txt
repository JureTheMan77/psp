cmake_minimum_required(VERSION 3.9)
project(OSK)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g0 -Wall -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align
-Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -std=c++17 -fexceptions -fno-rtti")

include_directories("/usr/local/pspdev/psp/sdk/include")
link_directories("/usr/local/pspdev/psp/sdk/lib")

add_executable(OSK src/main.cpp src/pspcallbacks.hpp)
#target_link_libraries(TIS2 src/main.cpp src/pspcallbacks.hpp)

#include_directories("/usr/local/pspdev/psp")