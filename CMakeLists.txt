cmake_minimum_required(VERSION 3.17)
project(nes-emulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(nes-emulator
        Bus.h
        Bus.cpp
        CPU.h
        CPU.cpp
        main.cpp)