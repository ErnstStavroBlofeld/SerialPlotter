cmake_minimum_required(VERSION 3.15)
project(ImGui)

include_directories(include)
include_directories(../glad/include)

add_library(ImGui STATIC include/imconfig.h include/imgui.h include/imgui_impl_glfw.h include/imgui_impl_opengl3.h
        include/imgui_internal.h include/imstb_rectpack.h include/imstb_textedit.h include/imstb_truetype.h src/imgui.cc
        src/imgui_demo.cc src/imgui_draw.cc src/imgui_impl_glfw.cc src/imgui_impl_opengl3.cc src/imgui_widgets.cc)
target_link_libraries(ImGui glfw glad)
