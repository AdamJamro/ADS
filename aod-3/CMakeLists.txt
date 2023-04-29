cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp GraphNode.cpp GraphNode.h GraphEdge.cpp GraphEdge.h Graph.cpp Graph.h)
add_executable(main ${SOURCE_FILES})
