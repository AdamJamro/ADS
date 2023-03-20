cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

add_executable(lab1 main.cpp FIFO.cpp FIFO.h LIFO.cpp LIFO.h linkedList.cpp linkedList.h circleList.cpp circleList.h)
