cmake_minimum_required(VERSION 3.23)
project(AOD_1)

set(CMAKE_CXX_STANDARD 14)

MATH(EXPR stack_size "8 * 8 * 1024 * 1024") # 8 MB
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(zad1 test_dfs_bfs.cpp graph.cpp graph.h)
add_executable(zad2 test_top_sort.cpp graph.cpp graph.h)
add_executable(zad3 test_detecting_connected_components.cpp graph.cpp graph.h tarjan_scc_solver.cpp)
add_executable(zad4 test_bipartite_components.cpp graph.cpp graph.h)
