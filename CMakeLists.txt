cmake_minimum_required(VERSION 3.16)

project(Moci)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(Sources/FirstLibrary)
add_subdirectory(Sources/FirstModule)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Bin)