cmake_minimum_required(VERSION 3.10)
project(Graphics)

set(CMAKE_CXX_STANDARD 11)

add_executable(Graphics main.cpp
        GraphicsObject.hpp
        GraphicsObject.cpp
        pspcallbacks.hpp GameApp.hpp GameApp.cpp Buttons.hpp)
include_directories("/usr/local/pspdev/psp/sdk/include")