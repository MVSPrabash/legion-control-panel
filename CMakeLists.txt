cmake_minimum_required(VERSION 3.20)

project(legion-control-panel)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)

add_executable(legion-control-panel
    src/main.cpp
)

target_link_libraries(legion-control-panel
    PRIVATE glfw
)

