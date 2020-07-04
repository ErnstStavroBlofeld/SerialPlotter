cmake_minimum_required(VERSION 3.15)
project(SerialPlotter)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(fmt REQUIRED)

add_subdirectory(lib/glad)
include_directories(lib/glad/include)

add_subdirectory(lib/ImGui)
include_directories(lib/ImGui/include)

add_subdirectory(lib/ImNodes)
include_directories(lib/ImNodes/include)

add_executable(SerialPlotter core/Main.cc core/Application.cc core/Application.h core/module/Module.h core/wrapper/Renderer.cc core/wrapper/Renderer.h core/module/output/Plotter.cc core/module/output/Plotter.h core/helper/widgets/Plot.cc core/helper/widgets/Plot.h core/helper/widgets/PlotType.h)
target_link_libraries(SerialPlotter Boost::system OpenGL::GL glfw glad ImGui ImNodes fmt::fmt)

if (UNIX)
    target_link_libraries(SerialPlotter dl pthread)
endif()
