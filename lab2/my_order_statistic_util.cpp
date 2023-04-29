//
// Created by adame on 17.04.2023.
//

#include "my_order_statistic_util.h"

#include <cmath>


long int my_order_statistic_util::comparison_counter = 0;
void my_order_statistic_util::reset_comparison_counter() { comparison_counter = 0; };
long int my_order_statistic_util::get_comparison_counter() { return comparison_counter; };

long int my_order_statistic_util::move_counter = 0;
void my_order_statistic_util::reset_move_counter() { move_counter = 0; };
long int my_order_statistic_util::get_move_counter() { return move_counter; };





int my_order_statistic_util::partition(std::vector<int> &vec, int left, int right, int pivot_index) {

    // place pivot at the beginning of the array
    std::swap(vec[pivot_index], vec[left]);
    move_counter += 3; //// delete
    pivot_index = left;

    int i = left;
    int j = right + 1;

    while (i < j) {
        while (++i < j && vec[i] < vec[pivot_index]) comparison_counter++; //// delete loop body
        while (--j >= i && vec[j] >= vec[pivot_index]) comparison_counter++; //// delete loop body
        if (i < j){
            std::swap(vec[i], vec[j]);
            move_counter += 3; //// delete
        }
    }
    // j == i - 1
    // j <- last element of low partition
    // i <- first element of high partition (or right + 1 if pivot == max_arr_val)

    std::swap(vec[pivot_index], vec[j]);
    move_counter += 3; //// delete


////     to be removed: (not a part of the algorithm)
    if (vec.size() >= 10 && vec.size() <= 50) {
        for (const auto &elem : vec ) {
            std::cout << elem << "\t";
        }
        std::cout << "<- used array[" << j << "] = " << vec[j] << " as pivot" << std::endl;
    }

    return j;
}

int my_order_statistic_util::random_partition(std::vector<int> &vec, int left, int right) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(left, right);
    int random_index = dist(mt);
    return my_order_statistic_util::partition(vec, left, right, random_index);
}

int my_order_statistic_util::findMedian(std::vector<int>& vec, int elements) {
    std::sort(vec.begin(), vec.end()); // takes constant time dependent on value of elements

    int tmp_val = static_cast<int>(elements * std::log2(elements)); ////delete
    move_counter += tmp_val;                                        ////delete
    comparison_counter += tmp_val;                                  ////delete

    int median_index = vec.size() / 2;
    return vec[median_index];
}

// finds the k-th order statistic of the vector
int my_order_statistic_util::quick_select(std::vector<int> &vec, int left, int right, int k) {
    const int elements = 9;

    while (true) {
        if (left == right)
            return vec[left];

        // Calculate the median of medians and return its index in the original vector
        const int N = right - left + 1;
        int _elements = elements; // it will be adjusted not to fall outside the vector scope thus we need copy
        std::vector<int> medians;
        for (int i = 0; i < N; i = i + _elements) {

            // if there's some residue subarray - shorten it
            if (i + _elements > N)
                _elements = N % _elements;

            std::vector<int> subgroup;
            for (auto it = vec.begin() + left + i;
                 it != vec.begin() + left + i + _elements; ++it)
                subgroup.emplace_back(*it);

            medians.push_back(findMedian(subgroup, elements));
        }

        // Now find the median of medians via quick_select
        int median_of_medians = (medians.size() == 1) ?
                                medians[0] : quick_select(medians, 0, static_cast<int>(medians.size() - 1),
                                           static_cast<int>(medians.size() / 2));

        // Find its original index
        int median_of_medians_index = -1;
        for (int i = 0; i < static_cast<int>(vec.size()); ++i) { //assert condition is true until we find the index
            if (vec[i] == median_of_medians) {
                median_of_medians_index = i;
                break;
            }
        }
        if (median_of_medians_index == -1)
            throw std::runtime_error("couldn't find median of medians' index");


        int pivot_index = median_of_medians_index; // Use it as a pivot
        pivot_index = partition(vec, left, right, pivot_index);

        comparison_counter ++; //// delete

        if (k - 1 == pivot_index)
            return vec[pivot_index];

        comparison_counter ++; //// delete

        if (k - 1 < pivot_index)
            right = pivot_index - 1;
        else
            left = pivot_index + 1;
    }

}

int my_order_statistic_util::random_select(std::vector<int> &vec, int left, int right, int k){
    while(true) {
        if (left == right)
            return vec[left];

        int pivot_index = random_partition(vec, left, right);
//        std::cout<<pivot_index<<std::endl;

        comparison_counter++; ////delete

        if (k - 1 == pivot_index)
            return vec[pivot_index];

        comparison_counter++; ////delete

        if (k - 1 < pivot_index)
            right = pivot_index - 1;
        else
            left = pivot_index + 1;
    }
}

void my_order_statistic_util::quick_sort(std::vector<int> &vec, int left, int right) {
    static int elements = 5;

    if (left == right)
        return;

    // PICK A PIVOT
    // Calculate median of medians and return its index in the original vector
    const int N = right - left + 1;
    int _elements = elements; // it will be adjusted not to fall outside the vector scope thus we need copy
    std::vector<int> medians;
    for (int i = 0; i < N; i = i + _elements) {

        // if there's some residue subarray - shorten it
        if (i + _elements > N)
            _elements = N % _elements;

        std::vector<int> subgroup;
        for (auto it = vec.begin() + left + i;
             it != vec.begin() + left + i + _elements; ++it)
            subgroup.emplace_back(*it);

        medians.push_back(findMedian(subgroup, elements));
    }

    // Find the median of medians via quick_select
    int median_of_medians = (medians.size() == 1) ?
                            medians[0] : quick_select(medians, 0, static_cast<int>(medians.size() - 1),
                                                      static_cast<int>(medians.size() / 2));

    // Find its original index
    int median_of_medians_index = -1;
    for (int i = 0; i < static_cast<int>(vec.size()); ++i) { //assert condition is true until we find the index
        if (vec[i] == median_of_medians) {
            median_of_medians_index = i;
            break;
        }
    }
    if (median_of_medians_index == -1)
        throw std::runtime_error("couldn't find median of medians' index");


    int pivot_index = median_of_medians_index; // Use it as a pivot
    pivot_index = partition(vec, left, right, pivot_index);


    quick_sort(vec, left, pivot_index - 1 >= left ? pivot_index - 1 : left);
    quick_sort(vec, pivot_index + 1 <= right ? pivot_index + 1 : right, right);



}

void my_order_statistic_util::sort(std::vector<int>& vec) {
    if (vec.empty())
        return;

    quick_sort(vec, 0, vec.size() - 1);
}


std::optional<int> my_order_statistic_util::find_kth_order_statistic(std::vector<int>& vec, int k) {
    int vector_size = static_cast<int>(vec.size());
    if (vector_size > 0 && k > 0 && k <= vector_size)
        return quick_select(vec, 0, vector_size - 1, k);
    else
        return {};
}
