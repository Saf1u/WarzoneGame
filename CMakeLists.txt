cmake_minimum_required(VERSION 3.19.2)
project(CopyOfCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CopyOfCode
        Player.cpp
        Player.h
       OrderDriver.cpp
        Map.h
        Map.cpp
        Cards.cpp
        Cards.h
        Orders.h
        Orders.cpp
        )
