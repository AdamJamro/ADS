#include <iostream>
#include "FIFO.cpp"
#include "LIFO.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

    //TESTING FIFO
    std::cout <<"======================" <<std::endl << "TESTING FIFO" << std::endl;

    FIFO<int> queue;
    for (int i = 0; i < 100; i++){
        queue.enqueue(2*i);
    }
    while ( !queue.isEmpty() ){
        std::cout << queue.dequeue() << std::endl;
    }


    //TESTING LIFO
    std::cout <<"======================" <<std::endl << "TESTING LIFO" << std::endl;

    LIFO<int> queue2;
    for (int i = 0; i < 100; i++){
        queue2.enqueue(200 - (2*i) - 1);
    }
    while ( !queue2.isEmpty() ){
        std::cout << queue2.dequeue() << std::endl;
    }

    return 0;
}
