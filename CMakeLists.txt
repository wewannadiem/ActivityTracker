cmake_minimum_required(VERSION 3.17)
project(ActivityTracker)

set(CMAKE_CXX_STANDARD 14)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.2/clang_64/lib/cmake/Qt5")
# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets Test REQUIRED)


add_executable(ActivityTracker main.cpp Activity.cpp Activity.h Register.cpp Register.h Window.cpp Window.h test/TestActivity.cpp test/TestActivity.h test/TestRegister.cpp test/TestRegister.h)
target_link_libraries(ActivityTracker Qt5::Widgets Qt5::Test)


