cmake_minimum_required(VERSION 3.17)
project(ActivityTracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(ActivityTracker main.cpp Activity.cpp Activity.h Register.cpp Register.h)