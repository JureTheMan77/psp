cmake_minimum_required(VERSION 3.10)
project(morph C)

set(CMAKE_C_STANDARD 99)

add_executable(morph morph.c)
include_directories("/usr/local/pspdev/psp/sdk/include")