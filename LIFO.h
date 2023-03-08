//
// Created by adame on 3/8/2023.
//

#ifndef LAB1_LIFO_H
#define LAB1_LIFO_H

#include <memory>
#include <stdexcept>

template <typename T>
class LIFO {
    struct Node {
        T value;
        std::shared_ptr<Node> next = nullptr;

        explicit Node(T _value): value(_value) {}
    };

    std::shared_ptr<Node> front = nullptr;
    std::shared_ptr<Node> back = nullptr;

public:
    void enqueue(T);
    T dequeue();
    bool isEmpty();
};


#endif //LAB1_LIFO_H
