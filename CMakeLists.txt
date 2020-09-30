cmake_minimum_required(VERSION 3.17)
project(DVS_EventProcessing)

set(CMAKE_CXX_STANDARD 14)

add_executable(DVS_EventProcessing main.cpp Event.h utils.h utils.cpp Event.cpp EventHandler.cpp EventHandler.h)
