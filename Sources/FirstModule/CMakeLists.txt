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