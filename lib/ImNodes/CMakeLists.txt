cmake_minimum_required(VERSION 3.15)
project(ImNodes)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(../ImGui/include)

add_library(ImNodes STATIC include/ImNodes.h include/ImNodesEz.h src/ImNodes.cc src/ImNodesEz.cc)
target_link_libraries(ImNodes ImGui)
