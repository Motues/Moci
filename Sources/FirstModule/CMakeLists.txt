cmake_minimum_required(VERSION 3.16)

project(Moci.FirstModule)

aux_source_directory(Sources c_courses)

add_executable(FirstModule ${c_courses})

target_include_directories(FirstModule PRIVATE Headers)

target_link_libraries(
    FirstModule
    PRIVATE fmt::fmt
    PRIVATE FirstLibrary
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../Bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../Bin)