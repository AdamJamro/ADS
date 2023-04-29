cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -g2)

add_executable("${PROJECT_NAME}" main.cpp my_sort_util.cpp my_sort_util.h my_order_statistic_util.cpp my_order_statistic_util.h my_binary_search_tool.cpp my_binary_search_tool.h)
add_executable(util_tests my_util_tests.cpp my_sort_util.cpp my_sort_util.h my_order_statistic_util.cpp my_order_statistic_util.h my_binary_search_tool.cpp my_order_statistic_util.h)
add_executable(test_order_util my_order_tests.cpp my_order_statistic_util.cpp my_order_statistic_util.h)
add_executable(make_array make_array.cpp)
