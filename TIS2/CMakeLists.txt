cmake_minimum_required(VERSION 3.9)
project(TIS2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -lpspdebugkb -fno-rtti -fexceptions -Wall -O2 -std=c++17")

include_directories("/usr/local/pspdev/psp/sdk/include")
link_directories("/usr/local/pspdev/psp/sdk/lib")

add_executable(TIS2 src/main.cpp src/pspcallbacks.hpp)
#target_link_libraries(TIS2 src/main.cpp src/pspcallbacks.hpp)

#include_directories("/usr/local/pspdev/psp")