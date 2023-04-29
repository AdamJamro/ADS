//
// Created by adame on 3/20/2023.
//

#include <utility>
#include <iostream>
#include "my_sort_util.h"

#define MAX_NUM_DISPLAY 20

long int my_sort_util::comparison_counter = 0;
void my_sort_util::reset_comparison_counter() { comparison_counter = 0; };
long int my_sort_util::get_comparison_counter() { return comparison_counter; };

long int my_sort_util::move_counter = 0;
void my_sort_util::reset_move_counter() { move_counter = 0; };
long int my_sort_util::get_move_counter() { return move_counter; };

void print_array(int* array, int size){
    for (int i = 0 ; i < size ; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void my_sort_util::insert_sort(int* array, int size) {
    insert_sort(array, 0, size -1, size);
}


void my_sort_util::insert_sort(int *array, int begin, int end, int size) {
    // each iteration will assume everything before array[i] is already sorted
    // and place one new next element (namely array[i]) in adequate position
    for (int i = begin + 1; i <= end; i++){
        // remember what value we add to pre-sorted left sub-array
        int key = array[i];
        move_counter++;

        int j;
        // shift every element to the right to make a spot for our key
        for (j = i - 1 ; j >= 0 && array[j] > key ; --j){
            array[j+1] = array[j];
            move_counter++;

            comparison_counter++;
        } // assert array[j] <= key

        // place the key in the right spot
        array[j+1] = key;
        move_counter++;

        if(size < MAX_NUM_DISPLAY){
            print_array(array, size);
        }
    }
}

void my_sort_util::bubble_sort(int* array, int size) {
    // used as a exit flag below
    char swapped;

    // loop to access each array element
    for (int step = 0; step < (size-1); ++step) {

        // reset to default
        swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size-step-1); ++i) {


            comparison_counter++;
            // compare values
            if (array[i] > array[i + 1]) {

                move_counter += 3;
                // swap if necessary
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                // set flag <-> remember that we're still sorting
                swapped = 1;
            }
        }

        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0)
            break;

        if(size < MAX_NUM_DISPLAY){
            print_array(array, size);
        }
    }
}

void my_sort_util::merge_sort(int* array, int size) {
    merge_sort(array, 0, size - 1, size);
}

void my_sort_util::merge_sort(int* array, int begin, int end, int size) {
    if (begin < end){
        //split array in half into two sub-arrays
        int mid = begin + (end - begin) / 2;

        merge_sort(array, begin, mid, size);
        merge_sort(array, mid + 1, end, size);

        //merge in them in linear time
        merge(array, begin, mid, end);

        if(size < MAX_NUM_DISPLAY){
            print_array(array, size);
        }
    }
}


void my_sort_util::merge(int* array, int begin, int mid, int end) {
    // split array into array[begin...mid], array[mid+1...end]
    int len_left = mid - begin + 1;
    int len_right = end - mid;

    int left_subarray[len_left], right_subarray[len_right];

    for (int i = 0 ; i < len_left ; i++) {
        left_subarray[i] = array[begin + i];
        move_counter++;
        comparison_counter++;
    }
    for (int i = 0 ; i < len_right ; i++) {
        right_subarray[i] = array[mid + 1 + i];
        move_counter++;
        comparison_counter++;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = begin;

    // merge the arrays
    while (i < len_left && j < len_right) {
        comparison_counter++;
        if (left_subarray[i] <= right_subarray[j]) {
            array[k++] = left_subarray[i++];
        }
        else {
            array[k++] = right_subarray[j++];
        }
        move_counter++;
    }

    while (i < len_left) {
        array[k++] = left_subarray[i++];
        move_counter++;
    }

    while (j < len_right) {
        array[k++] = right_subarray[j++];
        move_counter++;
    }
}

int my_sort_util::lomuto_partition(int* array, int begin, int end) {
    int pivot = array[begin];
    int i = begin;

    for (int j = begin + 1 ; j <= end ; ++j) {
        comparison_counter++;
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
            move_counter += 3;
        }
    }
    std::swap(array[i], array[begin]);
    move_counter += 3;
    return i;
}

// note that this implementation doesn't split array into less/greater or equal and strictly greater/less,
// in both subsets may occur values equal to the pivot
int my_sort_util::hoare_partition(int* array, int begin, int end) {
    int pivot_val = array[begin];
    int i = begin;
    int j = end + 1;

    while(true) {
        do {
            i++;
            comparison_counter++;
        } while (array[i] < pivot_val);
        do {
            j--;
            comparison_counter++;
        } while (array[j] > pivot_val);

        if (i >= j) {
            move_counter += 3;
            std::swap(array[begin], array[j]);
            return j;                               // j points to the index of the last element of the lower partition
        }
        else {
            std::swap(array[i], array[j]);
            move_counter += 3;
        }
    }
}

void my_sort_util::quick_sort(int* array, int begin, int end, int size) {
        if (begin < end){
//            int pivot = lomuto_partition(array, begin, end);
            int pivot = hoare_partition(array, begin, end);

            if(size < MAX_NUM_DISPLAY){
                print_array(array, size);
//                std::cout << "^pivot index=" << pivot << "; pivot val= " << array[pivot] <<"\n";
            }

            quick_sort(array, begin, pivot - 1, size);
            quick_sort(array, pivot + 1, end, size);
        }
}

void my_sort_util::quick_sort(int *array, int size) {
    quick_sort(array, 0, size - 1, size);
}

class my_sort_util::pivot {
public:
    pivot(int _left, int _right) : left(_left), right(_right) {};
    int left;
    int right;
};

void my_sort_util::dual_pivot_quick_sort(int *array, int begin, int end, int size) {
    if (begin >= end) {
        return;
    }

    pivot pivot = dual_pivot_partition_count_strategy(array, begin, end);

    if(size < MAX_NUM_DISPLAY){
        print_array(array, size);
    }

    dual_pivot_quick_sort(array, begin, pivot.left - 1, size);
    dual_pivot_quick_sort(array, pivot.left + 1, pivot.right - 1, size);
    dual_pivot_quick_sort(array, pivot.right + 1, end, size);


}

my_sort_util::pivot my_sort_util::dual_pivot_partition(int* array, int begin, int end) {
    // pick left and right pivot as first and last elements of the array
    if (array[begin] > array[end]){
        std::swap(array[begin],array[end]);
    }

    pivot pivot(begin, end);


    int left_index = begin + 1;
    int right_index = end - 1;

    int i = begin + 1;
    while (i <= right_index) {
        if (array[i] < array[pivot.left]) {
            std::swap(array[i], array[left_index]);
            left_index++;
            i++;
        }
        else if ( array[i] > array[pivot.right]) {
            std::swap(array[i], array[right_index]);
            right_index--;
        }
        else i++;
    }

    std::swap(array[begin], array[--left_index]);
    std::swap(array[end], array[++right_index]);
    pivot.left = left_index;
    pivot.right = right_index;

    return pivot;
}

my_sort_util::pivot my_sort_util::dual_pivot_partition_count_strategy(int* array, int begin, int end) {
    // pick left and right pivot as first and last elements of the array
    comparison_counter++;
    if (array[begin] > array[end]){
        std::swap(array[begin],array[end]);
    }

    pivot pivot(begin, end);

    // count
    int num_of_low_elements = 0;
    int num_of_high_elements = 0;

    for (int i = begin + 1; i <= end - 1 ; i++) {
        comparison_counter+=2;
        if (array[i] < array[pivot.left]) {
            num_of_low_elements++;
            comparison_counter--;
        }
        else if (array[i] > array[pivot.right]) {
            num_of_high_elements++;
        }
    }


    int left_index = begin + 1;
    int right_index = end - 1;
    int i = begin + 1;

    if (num_of_high_elements < num_of_low_elements) {
        while (i <= right_index) {
            comparison_counter += 2;
            if (array[i] < array[pivot.left]) {
                std::swap(array[i], array[left_index]);
                left_index++;
                i++;

                move_counter+=3;
                comparison_counter--;
            }
            else if ( array[i] > array[pivot.right]) {
                std::swap(array[i], array[right_index]);
                right_index--;

                move_counter+=3;
            }
            else {
                i++;
                comparison_counter-=2;
            }
        }
    }
    else {
        while (i <= right_index) {
            comparison_counter += 2;

            if (array[i] > array[pivot.right]) {
                std::swap(array[i], array[right_index]);
                right_index--;

                move_counter+=3;
                comparison_counter--;
            }
            else if (array[i] < array[pivot.left]) {
                std::swap(array[i], array[left_index]);
                left_index++;
                i++;

                move_counter+=3;
            }
            else {
                i++;
                comparison_counter-=2;
            }
        }
    }

    comparison_counter += 6;
    std::swap(array[begin], array[--left_index]);
    std::swap(array[end], array[++right_index]);
    pivot.left = left_index;
    pivot.right = right_index;

    return pivot;
}

void my_sort_util::dual_pivot_quick_sort(int *array, int size) {
    dual_pivot_quick_sort(array, 0, size - 1, size);
}

void my_sort_util::quick_sort_with_insertion(int* array, int begin, int end, int size) {
    if (begin < end){

        if (end - begin <= 5) {
            insert_sort(array, begin, end, size);
            return;
        }

//            int pivot = lomuto_partition(array, begin, end);
        int pivot = hoare_partition(array, begin, end);

        if(size < MAX_NUM_DISPLAY){
            print_array(array, size);
        }

        quick_sort_with_insertion(array, begin, pivot - 1, size);
        quick_sort_with_insertion(array, pivot + 1, end, size);
    }
}

void my_sort_util::quick_sort_with_insertion(int *array, int size) {
    quick_sort_with_insertion(array, 0 , size - 1, size);
}

