cmake_minimum_required(VERSION 3.16)

project(Moci)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Bin)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(Sources/FirstLibrary)
add_subdirectory(Sources/FirstModule)
