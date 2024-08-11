cmake_minimum_required(VERSION 3.16)

project(Moci)

find_package(fmt CONFIG REQUIRED)

add_executable(test Sources/main.cpp)

target_link_libraries(test PRIVATE fmt::fmt)
