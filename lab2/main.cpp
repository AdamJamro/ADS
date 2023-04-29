#include <iostream>
#include <random>
#include <vector>
#include <sstream>

#include "my_sort_util.h"
#include "my_order_statistic_util.h"
#include "my_binary_search_tool.h"

void run_sorting_tests();
void run_order_tests();
void run_binary_search_tests();
void run_order_sort_tests();

int main() {
    //// GREET THE USER
    std::cout << "Hello, World!" << std::endl;


    run_order_sort_tests();
//    run_order_tests();
//
//    run_binary_search_tests();

    return 0;
}

void run_order_sort_tests(){
    //// TAKE INPUT NUMBER OF ORDER STATISTIC & ARRAY FROM STD::CIN
    std::vector<int> vec;
    int size = 0;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);
    while(line >> input) {
        vec.push_back(strtol(input.c_str(), nullptr, 10));
        size++;
    }

    //// PRINT ARRAY INPUT
    std::vector<int> vec_copy(vec);
    std::sort(vec_copy.begin(), vec_copy.end());
    for ( auto elem : vec_copy ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- sorted array" << std::endl;

    for ( auto elem : vec ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- original array" << std::endl;




    ////SORT
    std::vector<int> tmp_vec(vec);
    my_order_statistic_util::sort(tmp_vec);

    ////display
    for ( auto elem : tmp_vec ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- array after selection" << std::endl;
}

void run_binary_search_tests() {
    //// TAKE INPUT NUMBER OF ORDER STATISTIC & ARRAY FROM STD::CIN
    std::vector<int> vec;
    int size = 0;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);
    while(line >> input) {
        vec.push_back(strtol(input.c_str(), nullptr, 10));
        size++;
    }

    //// PRINT ARRAY INPUT
    std::vector<int> vec_copy(vec);
    std::sort(vec_copy.begin(), vec_copy.end());
    for ( auto elem : vec_copy ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- sorted array" << std::endl;


    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(0, static_cast<int>(vec_copy.size()));
    int random_number = dist(mt);

    if (my_binary_search_tool::has_element(vec_copy, random_number)){
        std::cout << "vector contains: " << random_number << std::endl;
    }
    else {
        std::cout << "vector does not contain: " << random_number << std::endl;
    }
}

void run_order_tests() {
    //// TAKE INPUT NUMBER OF ORDER STATISTIC & ARRAY FROM STD::CIN
    std::vector<int> vec;
    int size = 0;
    int order = 0;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);
    if (line >> input) {
        order = strtol(input.c_str(), nullptr, 10);
    }
    while(line >> input) {
        vec.push_back(strtol(input.c_str(), nullptr, 10));
        size++;
    }

    //// PRINT ARRAY INPUT
    std::vector<int> vec_copy(vec);
    std::sort(vec_copy.begin(), vec_copy.end());
    for ( auto elem : vec_copy ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- sorted array" << std::endl;

    for ( auto elem : vec ) {
        std::cout << elem << "\t";
    }
    std::cout << "<- original array" << std::endl;





    std::vector<int> tmp_vec(vec);

    std::optional<int> kth_statistic = my_order_statistic_util::find_kth_order_statistic(tmp_vec, order);
    if (kth_statistic){
        for ( auto elem : tmp_vec ) {
            std::cout << elem << "\t";
        }
        std::cout << "<- array after selection" << std::endl;

        for (int i = 0; i < order - 1;  i++) {
            std::cout << " \t";
        }
        std::cout << kth_statistic.value() ;
        for (int i = order - 1; i < size;  i++) {
            std::cout << " \t";
        }
        std::cout << "<- " << order << ". order statistic\n";
    }
}

void run_sorting_tests() {
    //// TAKE INPUT ARRAY FROM STD::CIN
    std::vector<int> vector_array;
    int size = 0;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);
    while(line >> input) {
        vector_array.push_back(strtol(input.c_str(), nullptr, 10));
        size++;
    }
    int* array = &vector_array[0];


    //// PRINT ARRAY INPUT for size < 40;
    if (size < 40) {
        for (int i = 0 ; i < size ; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << " <- original array" << std::endl;
    }
    //// CHOOSE SORTING ALGORITHM
//    my_sort_util::merge_sort(array, size);
//    my_sort_util::bubble_sort(array, size);
//    my_sort_util::insert_sort(array, size);
//    my_sort_util::quick_sort(array, size);
//    my_sort_util::dual_pivot_quick_sort(array, size);
    my_sort_util::quick_sort_with_insertion(array, size);

    //// print stats
    std::cout << "total num of comparisons: " << my_sort_util::get_comparison_counter() << "\n";
    std::cout << "total num of moved keys: " << my_sort_util::get_move_counter() << "\n";

    //// PRINT SORTED ARRAY for array size < 40
    if (size < 40) {
        for (int i = 0 ; i < size ; i++) {
            printf("%02d ",array[i]);
        }
        std::cout << " <- final result array\n";
    }

    std::cout << std::endl;


    //// ASSERT ARRAY IS SORTED;
    for (int i = 0 ; i + 1 < size ; i++) {
        if (array[i] > array[i+1]){
            std::cout << "znowu w zyciu mi nie wyszlo\n";
            return; // return 1
        }
    }

}