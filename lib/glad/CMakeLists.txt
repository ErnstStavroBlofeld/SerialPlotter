cmake_minimum_required(VERSION 3.15)
project(glad)

include_directories(include)

add_library(glad STATIC include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
