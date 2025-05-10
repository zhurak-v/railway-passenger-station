cmake_minimum_required(VERSION 3.20)

project(coursework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(coursework ${SRC_FILES})

target_include_directories(coursework PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)