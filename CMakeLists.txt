cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Event.h utils.h utils.cpp Event.cpp EventHandler.cpp EventHandler.h)