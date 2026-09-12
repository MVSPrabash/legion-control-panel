cmake_minimum_required(VERSION 3.20)

project(legion-control-panel)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(legion-control-panel
    src/main.cpp

    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp

    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(legion-control-panel
    PRIVATE
        external/imgui
        external/imgui/backends
)

target_link_libraries(legion-control-panel
    PRIVATE
        glfw
        OpenGL::GL
)

