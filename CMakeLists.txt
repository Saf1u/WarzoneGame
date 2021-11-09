cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp CommandProcessor.cpp CommandProcessor.h GameEngine.cpp GameEngine.h FileCommandProcessor.cpp FileCommandProcessor.h FileCommandProcessorAdapter.cpp FileCommandProcessorAdapter.h)