//
// Created by adame on 3/22/2023.
//

#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
//#include "my_sort_util.h"
//#include "my_order_statistic_util.h"
#include "my_binary_search_tool.h"

#define NUM_OF_TRIALS 100

void make_random_array(int *&array, int size);
void make_random_vector(std::vector<int> &array, int size);
std::vector<int> make_sorted_vector(int size);
int stat_vector_size = 0;
std::vector<int> data_sizes_vector;

std::vector<std::vector<int>> num_of_compares_vector;
std::vector<std::vector<int>> num_of_moves_vector;
std::vector<std::vector<int>> execution_time_vector;


namespace Random{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist (0, 1);
    double uniform_number() {
        return dist(mt);
    }
}

int main() {


    for (int n = 1 ; n <= 100 ; n++) {
        data_sizes_vector.push_back(n * 1000);
        stat_vector_size++;
    }
    num_of_compares_vector.reserve(stat_vector_size);
//    num_of_moves_vector.reserve(stat_vector_size);
    execution_time_vector.reserve(stat_vector_size);

    for (auto size : data_sizes_vector){
        std::cout << "size=" << size << std::endl;

        std::vector<int> num_of_compares;
//        std::vector<int> num_of_moves;
        std::vector<int> execution_time;


//            std::cout << "size = " << size << std::endl;


        for (int k = 0 ; k < NUM_OF_TRIALS ; k++) {
//            std::cout << "trial no." << k + 1 << std::endl;

//            int* array = new int[size];
//            make_random_array(array,size);
            std::vector<int> vec;
//            vec.reserve(size);
//            make_random_vector(vec, size);
            vec = make_sorted_vector(size);

            my_binary_search_tool::reset_comparison_counter();
//            my_binary_search_tool::reset_move_counter();
            auto start = std::chrono::high_resolution_clock::now();
            int random_key = static_cast<int>(200 * Random::uniform_number());

            //////////////////////////////////////////////// CHOOSE FUNCTION TO TEST //////////////////////////
            my_binary_search_tool::has_element(vec, random_key);

            auto stop = std::chrono::high_resolution_clock::now();
            num_of_compares.push_back(my_binary_search_tool::get_comparison_counter());
//            num_of_moves.push_back(my_binary_search_tool::get_move_counter());
            execution_time.push_back(static_cast<int>((stop-start).count()));

//            delete[] array;
        }

        num_of_compares_vector.push_back(num_of_compares);
//        num_of_moves_vector.push_back(num_of_moves);
        execution_time_vector.push_back(execution_time);

    }


    std::ofstream file;
    file.open("data.txt");

    for (int k = 0 ; k < NUM_OF_TRIALS ; k++){
        for (int i = 0 ; i < stat_vector_size ; i++) {
            file << num_of_compares_vector[i][k] << ",";
        }
        file << std::endl;
    }
    file << std::endl;
//
//    for (int k = 0 ; k < NUM_OF_TRIALS ; k++){
//        for (int i = 0 ; i < stat_vector_size ; i++) {
//            file << num_of_moves_vector[i][k] << ",";
//        }
//        file << std::endl;
//    }
//
    for (int k = 0 ; k < NUM_OF_TRIALS ; k++){
        for (int i = 0 ; i < stat_vector_size ; i++) {
            file << execution_time_vector[i][k] << ",";
        }
        file << std::endl;
    }

    file.close();

    return 0;
}


void make_random_array(int* &array, int size){
    for (int i = 0 ; i < size ; i++){
        array[i] = static_cast<int>(2 * size * Random::uniform_number());
//                    std::cout << "array [" << i << "] = " << array[i] << "\n";
    }
}

void make_random_vector(std::vector<int> &vec, int size){

    for (int i = 0 ; i < size ; i++){
        int elem = static_cast<int>(2 * vec.size() * Random::uniform_number());
        vec.push_back(elem);
//        std::cout << "array [" << i << "] = " << vec[i] << "\n";
    }
}

std::vector<int> make_sorted_vector(int size) {
    std::vector<int> vec;
    vec.reserve(size);
    for ( int i = 0 ; i < size ; i++ ) {
        vec.push_back(i);
    }
    return vec;
}