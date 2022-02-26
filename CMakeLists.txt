cmake_minimum_required(VERSION 3.8)
project(svg_creator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Qunused-arguments")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

set(SOURCE_FILES main.cpp src/Graphics.cpp src/include/Graphics.h src/SvgParser.cpp src/include/SvgParser.h)

add_executable(svg_creator ${SOURCE_FILES})
