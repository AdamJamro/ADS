//
// Created by adame on 17.04.2023.
//

#ifndef LAB2_MY_ORDER_STATISTIC_UTIL_H
#define LAB2_MY_ORDER_STATISTIC_UTIL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <random>

class my_order_statistic_util {
private:
    static int partition(std::vector<int>&, int, int, int);
    static int random_partition(std::vector<int>&, int, int);
    static int quick_select(std::vector<int> &vec, int left, int right, int k);
    static int random_select(std::vector<int> &vec, int left, int right, int k);

    //// to be deleted
    static long comparison_counter;
    static long move_counter;

public:
    static std::optional<int> find_kth_order_statistic(std::vector<int> &vec, int k);
    static int findMedian(std::vector<int> &vec, int elements);
    static void sort(std::vector<int> &vec);
    static void quick_sort(std::vector<int> &vec, int left, int right);

    //// to be deleted
    static void reset_comparison_counter();
    static long get_comparison_counter();
    static void reset_move_counter();
    static long get_move_counter();
};


#endif //LAB2_MY_ORDER_STATISTIC_UTIL_H
