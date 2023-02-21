cmake_minimum_required(VERSION 3.17)
project(ActivityTracker)

set(CMAKE_CXX_STANDARD 14)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tell CMake to create the helloworld executable
#add_executable(qtHelloWorld main.cpp)
#add_executable(qtHelloWorld WIN32 main.cpp)

# Use the Widgets module from Qt 5.

add_executable(ActivityTracker main.cpp Activity.cpp Activity.h Register.cpp Register.h Window.cpp Window.h test/TestActivity.cpp test/TestActivity.h test/TestRegister.cpp test/TestRegister.h)
target_link_libraries(ActivityTracker Qt5::Widgets)


