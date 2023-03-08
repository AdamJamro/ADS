//
// Created by adame on 3/8/2023.
//

#include "LIFO.h"

template <class T>
void LIFO<T>::enqueue(T _value) {
    if (isEmpty()) {
        front = std::make_shared<Node>(_value);
    } else {
        std::shared_ptr<Node> oldFront = front;
        front = std::make_shared<Node>(_value);
        front->next = oldFront;
    }
}

template <class T>
T LIFO<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Nothing to dequeue");

    T value = front->value;
    front = front->next;

    return value;
}

template <class T>
bool LIFO<T>::isEmpty() {
    return front == nullptr;
}
