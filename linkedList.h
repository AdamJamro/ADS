//
// Created by adame on 3/9/2023.
//

#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H

#include <memory>
#include <stdexcept>

template <typename T>
class linkedList {
    struct Node {
        T value;
        std::shared_ptr<Node> next = nullptr;

        explicit Node(T _value): value(_value) {}
    };

    std::shared_ptr<Node> head = nullptr;
//    std::shared_ptr<Node> current = nullptr;

public:
    void insert(T value){

        std::shared_ptr<Node> temp = std::make_shared<Node>(value);

        if (this->isEmpty()){
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void remove(T value){
        //TODO
    }

    bool isEmpty(){
        return head == nullptr;
    }
};


#endif //LAB1_LINKEDLIST_H
