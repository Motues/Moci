cmake_minimum_required(VERSION 3.16)

project(Moci.FirstLibrary)

aux_source_directory(Sources c_courses)

add_library(FirstLibrary ${c_courses})

target_include_directories(FirstLibrary PUBLIC Headers)
