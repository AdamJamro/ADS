//
// Created by adame on 17.04.2023.
//
#include <fstream>
#include "my_order_statistic_util.h"


int main() {
    std::vector<int> vec = { 0, 22, 0, 5, 7, 12, 16, 22, 47, 5, 51, 42, 36, 52, 27, 55, 58, 58, 16, 38, 23, 6, 2, 50, 28, 50, 7, 11, 54, 53 };
//    std::vector<int> vec = { 3, 2, 1, 6, 5, 4, 4, 4};

    std::ofstream results("./quick_select_results");


    for ( auto elem : vec ) {
        results << elem << "\t";
    }
    results << "<- original array" << std::endl;


    std::vector<int> vec_copy(vec);
    std::sort(vec_copy.begin(), vec_copy.end());
    for ( auto elem : vec_copy ) {
        results << elem << "\t";
    }
    results << "<- sorted array" << std::endl;


    for ( int k = 1 ; k <= static_cast<int>(vec.size()) ; k++) {
        std::vector<int> tmp_vec(vec);

        std::optional<int> kth_statistic = my_order_statistic_util::find_kth_order_statistic(tmp_vec, k);
        if (kth_statistic){
//            for ( auto elem : tmp_vec ) {
//                results << elem << "\t";
//            }
//            results << "<- array after " << k <<". selection" << std::endl;

            for (int i = 0; i < k - 1;  i++) {
                results << " \t";
            }
            results << kth_statistic.value() << "\n";
        }
    }


    return 0;
}