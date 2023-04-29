//
// Created by adame on 3/20/2023.
//

#ifndef LAB2_MY_SORT_UTIL_H
#define LAB2_MY_SORT_UTIL_H


class my_sort_util {
public:
    class pivot;
    static long int get_comparison_counter();
    static long int get_move_counter();
    static void reset_comparison_counter();
    static void reset_move_counter();
    static void insert_sort(int *array,int size);
    static void insert_sort(int *array, int begin, int end, int size);
    static void bubble_sort(int *array,int size);
    static void merge_sort(int *array,int begin,int end, int size);
    static void merge_sort(int *array, int size);
    static void quick_sort(int *array,int size);
    static void quick_sort(int *array, int begin, int end, int size);
    static void quick_sort_with_insertion(int *array, int begin, int end, int size);
    static void quick_sort_with_insertion(int *array, int size);
    static void dual_pivot_quick_sort(int *array, int begin, int end, int size);
    static void dual_pivot_quick_sort(int *array, int size);

private:
    static void merge(int*,int,int,int);
    static int lomuto_partition(int*,int,int);
    static int hoare_partition(int*,int,int);
    static long int comparison_counter;
    static long int move_counter;
    static pivot dual_pivot_partition(int* array, int begin, int end);
    static pivot dual_pivot_partition_count_strategy(int* array, int begin, int end);
};


#endif //LAB2_MY_SORT_UTIL_H
