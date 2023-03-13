//
// Created by adame on 3/9/2023.
//

#include "circleList.h"
#include <iostream>

template <class T>
struct circleList<T>::Node {
    T value;
    std::shared_ptr<Node> next = nullptr;

    explicit Node(T _value): value(_value) {}
};

template <class T>
void circleList<T>::insert(T value){
    std::shared_ptr<Node> temp = std::make_shared<Node>(value);

    if (head == nullptr){
        head = temp;
        head->next = head;
    } else if(head->next == head){
        head->next = temp;
        temp->next = head;
    } else {
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
}

template <class T>
bool circleList<T>::remove(T key){
//    if (head->value == key){
//        auto key_node = head.get();
//        head = head.next;
//        delete key_node;
//        return true;
//    }

    Node *current = head.get();
    while(current->next != head){
        if(current->next->value == key){
            auto key_node = current->next.get();
            current->next = current->next->next;
//            delete key_node;
            return true;
        }
        current = current->next.get();
    }
    if (head->value == key){
        auto key_node = head.get();
        current->next = head->next;
//        delete key_node;
        return true;
    }
    return false;
}

template <class T>
std::shared_ptr<typename circleList<T>::Node> circleList<T>::search(T key){

    if(head == nullptr){
        throw std::underflow_error("tried searching through empty list");
    }


    Node* current = head.get();
//    std::weak_ptr<Node> current = head;

    if(head->value == key){
        return head;
    }

    while(current->next != nullptr){
        if(current->next == head){
            return nullptr;
        }
        if(current->next->value == key){
            return current->next;
        }
        current = current->next.get();
    }
    return nullptr;
}

template <class T>
bool circleList<T>::isEmpty(){
    return head == nullptr;
}

template<typename T>
circleList<T>* circleList<T>::merge(circleList<T>* list) {
    if (head == nullptr) {
        head = list->head;
        return this;
    }
    if (list->head == nullptr) {
        return this;
    }

    Node* current = head.get();

    auto temp_tail = head->next;
    head->next = list->head->next;
    list->head->next = temp_tail;
    head = temp_tail;

    return this;
}

template<typename T>
void circleList<T>::print() {
    if (head == nullptr) {
        return;
    }

    Node* current = head.get();

    while(current->next != head){
        std::cout<< current->value << std::endl;
        current = current->next.get();
    }
}

template<typename T>
circleList<T>::~circleList() {
    delete head;
}


