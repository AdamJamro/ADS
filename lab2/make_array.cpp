//
// Created by adame on 3/21/2023.
//

#include <iostream>
#include <random>
#include <cstring>


namespace Random{
    std::random_device rd;
    std::mt19937 mt(rd());
}

int* random_array(int);


int main(int argv, char** argc){
    if (argv < 2) {
        return 1;
    }

    int size = strtol(argc[1], nullptr, 10);


    if (argv == 3){ //create sorted array
        if (std::strcmp(argc[2], "desc") != 0) {
            for (int i = 0 ; i < size ; ++i) {
                std::cout << 2 * size - (2 * i + 1) << " ";
            }
            std::cout << std::endl;
            return 0;
        }

        if (std::strcmp(argc[2], "asc") != 0) {
            for (int i = 0 ; i < size ; ++i) {
                std::cout << 2 * i + 1 << " ";
            }
            std::cout << std::endl;
            return 0;
        }
    }

    else{   //create random array

        int* array = random_array(size);
        for ( int i = 0 ; i < size ; i++ ) {
            std::cout << array[i] << " ";
        }

        std::cout << std::endl;
        delete array;
    }

    return 0;
}

int* random_array(int size) {
    int* array = new int[size];
    std::uniform_int_distribution<int> dist (0,size * 2 - 1);

    for (int i = 0 ; i < size ; ++i) {
        array[i] = dist(Random::mt);
    }

    return array;
}