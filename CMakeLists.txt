cmake_minimum_required(VERSION 3.21)
project(svg_creator)

set(CMAKE_CXX_STANDARD 14)

add_executable(svg_creator main.cpp src/Shape.cpp src/include/Shape.h src/Circle.cpp src/include/Circle.h src/Rectangle.cpp src/include/Rectangle.h src/Polygone.cpp src/include/Polygone.h src/Window.cpp src/include/Window.h)
