cmake_minimum_required(VERSION 3.15)
project(Tickets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic
)


file(GLOB OTHER_SOURCES otherVariants/*_*.cpp)

foreach(src_file ${OTHER_SOURCES})
    get_filename_component(filename ${src_file} NAME_WE)
    add_executable(${filename} ${src_file})
    set_target_properties(${filename} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/otherVariants/bin
    )
    target_compile_options(${filename} PRIVATE
        -Wall -Wextra -Wpedantic
    )
endforeach()

