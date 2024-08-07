cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include third_party/nlohmann/json/include/)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(LibraryManagementSystem ${SOURCES})

# Unit testing
enable_testing()
#add_subdirectory(tests)
