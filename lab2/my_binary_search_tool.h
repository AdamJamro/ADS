//
// Created by adame on 19.04.2023.
//

#ifndef LAB2_MY_BINARY_SEARCH_TOOL_H
#define LAB2_MY_BINARY_SEARCH_TOOL_H


#include <vector>

class my_binary_search_tool {
private:
    static bool binary_search(std::vector<int> &vec, int left, int right, int key);

    //// to be deleted
    static long comparison_counter;



public:
    [[maybe_unused]] static bool has_element(std::vector<int> &vec, int key);

    //// to be deleted
    static void reset_comparison_counter();
    static long get_comparison_counter();
};


#endif //LAB2_MY_BINARY_SEARCH_TOOL_H
