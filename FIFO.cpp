//
// Created by adame on 3/8/2023.
//

#include "FIFO.h"

template <class T>
void FIFO<T>::enqueue(T _value) {
    if (isEmpty()) {
        front = std::make_shared<Node>(_value);
        back = front;
    } else {
        back->next = std::make_shared<Node>(_value);
        back = back->next;
    }
}

template <class T>
T FIFO<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Nothing to dequeue");

    T value = front->value;
    front = front->next;

    return value;
}

template <class T>
bool FIFO<T>::isEmpty() {
    return front == nullptr;
}

