cmake_minimum_required(VERSION 3.17)
project(ActivityTracker)

set(CMAKE_CXX_STANDARD 14)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)



set(SOURCE_FILES runAllTests.cpp testRegister.cpp)
add_executable(runAllTests ${SOURCE_FILES})
target_link_libraries(runAllTests gtest)