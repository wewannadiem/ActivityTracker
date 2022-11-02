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


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)

add_executable(ActivityTracker main.cpp Activity.cpp Activity.h Register.cpp Register.h Window.cpp Window.h test/runAllTests.cpp test/testRegister.cpp)
target_link_libraries(ActivityTracker Qt5::Widgets gtest_main)


