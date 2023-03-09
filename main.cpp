#include <iostream>
#include "FIFO.cpp"
#include "LIFO.cpp"
#include "linkedList.h"
#include "linkedList.cpp"
#include "circleList.h"
#include "circleList.cpp"
#include <chrono>
#include <random>
#include <bits/stdc++.h>


int const numOfListElems = 10000;

namespace Random{
    std::random_device rd;
    std::mt19937  mt(rd());
    std::uniform_int_distribution<int> dist (0,99);
    int nextInt(){
        return dist(mt);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

      ////TESTING FIFO
//    std::cout <<"======================" <<std::endl << "TESTING FIFO" << std::endl;
//
//    auto queue = std::make_unique<FIFO<int>>();
//    for (int i = 0; i < 100; i++){
//        queue->enqueue(2*i);
//    }
//    while ( !queue->isEmpty() ){
//        std::cout << queue->dequeue() << std::endl;
//    }
//

      ////TESTING LIFO
//    std::cout <<"======================" <<std::endl << "TESTING LIFO" << std::endl;
//
//    auto queue2 = std::make_unique<LIFO<int>>();
//    for (int i = 0; i < 100; i++){
//        queue2->enqueue(200 - (2*i) - 1);
//    }
//    while ( !queue2->isEmpty() ){
//        std::cout << queue2->dequeue() << std::endl;
//    }


    ////TESTING (ONE DIRECTIONAL) LINKED LIST
//    std::cout <<"======================" <<std::endl << "TESTING linkedList" << std::endl;
//
//
//
//    auto* list = new linkedList<int>();
//    for (int i = 0; i < numOfListElems; i++){
//        list->insert(i);
//    }
//    //testing search for the same element which is approximately in approx 8/10 of the distance from head node
//    for (int i = 0; i < 20; i++){
//        auto start = std::chrono::high_resolution_clock::now();
//        list->search(numOfListElems*1/10);
//        auto finish = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> elapsed = finish - start;
//
//        std::cout<<"time spent finding fixed element away from head: "<< elapsed.count() <<std::endl;
//    }
//    for (int i = 0; i < 20; i++){
//        auto start = std::chrono::high_resolution_clock::now();
//        list->search(numOfListElems*9/10);
//        auto finish = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> elapsed = finish - start;
//
//        std::cout<<"time spent finding fixed element close to head: "<< elapsed.count() <<std::endl;
//    }
//    //testing search for random values
//    for (int i = 0; i < 20; i++){
//
//        auto start = std::chrono::high_resolution_clock::now();
//        auto tmpNode = list->search(numOfListElems*Random::nextInt()/100);
//        auto finish = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> elapsed = finish - start;
//
//        //std::cout<<list->getHead().use_count()<<std::endl;
//        std::cout<<"time spent finding a random element: "<< elapsed.count() <<std::endl;
//    }
//    //testing remove
//    for(int i = numOfListElems * 99/100; i < numOfListElems * 101/100 ; i++){
//        std::cout<<"removing element "<<i<<" was successful: "<<list->remove(i)<<std::endl;
//    }
//    //testing merge function
//    auto list2 = new linkedList<int>();
//    for (int i = 0; i < numOfListElems; i++){
//        list->insert(numOfListElems - i);
//    }
//    list->merge(list2); //we know it isint empty so:
//    list->print();
//    delete list;
//    delete list2;


    ////TESTING circular linked list
    auto* cList = new circleList<int>();
    auto* cList2 = new circleList<int>();
    for ( int i = 0 ; i < numOfListElems ; i++){
        cList->insert(Random::nextInt());
        cList2->insert(Random::nextInt());
    }

    for( int i = 0 ; i < 3 ; i++){
        auto fixedElement = Random::nextInt();
        for (int j = 0 ; j < 10 ; j++){
            auto start = std::chrono::high_resolution_clock::now();

            auto tmpNode = cList->search(fixedElement);

            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;

            std::cout<<"time spent finding a fixed element no."<<i<<" is: "<< elapsed.count() <<std::endl;
        }
    }

    for (int i = 0 ; i < 20 ; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        auto tmpNode = cList->search(Random::nextInt());

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;

        std::cout << "time spent finding a random element no." << i << " is: " << elapsed.count() << std::endl;
    }

    cList->merge(cList2);
    cList->print();





        return 0;
}




