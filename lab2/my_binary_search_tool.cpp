//
// Created by adame on 19.04.2023.
//

#include <algorithm>
#include <iostream>
#include "my_binary_search_tool.h"

#define MAX_NUM_DISPLAY 50


long int my_binary_search_tool::comparison_counter = 0;
void my_binary_search_tool::reset_comparison_counter() { comparison_counter = 0; };
long int my_binary_search_tool::get_comparison_counter() { return comparison_counter; };


[[maybe_unused]] bool my_binary_search_tool::has_element(std::vector<int> &vec, int key) {

    // assert array is sorted
    for (auto iterator = vec.begin() ; iterator + 1 < vec.end() ; iterator++) {
        if (iterator[0] > iterator[1]) {
            std::sort(vec.begin(), vec.end());
            break;
        }
    }

    int left = 0, right = static_cast<int>(vec.size() - 1);
    return my_binary_search_tool::binary_search(vec, left, right, key);
}

bool my_binary_search_tool::binary_search(std::vector<int> &vec, int left, int right, int key) {

    ////to delete: start
    if (static_cast<int>(vec.size()) < 50) {
        for (auto it = vec.begin() + left ; it < vec.begin() + right + 1; it++) {
            std::cout << *it << '\t';
        }
        std::cout << std::endl;
    }
    //// end

    comparison_counter ++; ////delete

    if ( left == right && vec[left] != key)
        return false;

    int mid = left + (right - left) / 2;


    comparison_counter ++; ////delete

    if (vec[mid] > key)
        return binary_search(vec, left, mid - 1, key);

    comparison_counter ++; ////delete

    if (vec[mid] < key)
        return binary_search(vec, mid + 1, right, key);

    comparison_counter ++; ////delete

    if (vec[mid] == key)
        return true;

    return false;
}
