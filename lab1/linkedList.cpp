//
// Created by adame on 3/9/2023.
//

#include <iostream>
#include "linkedList.h"

template <class T>
struct linkedList<T>::Node {
    T value;
    std::shared_ptr<Node> next = nullptr;

    explicit Node(T _value): value(_value) {}
};

template <class T>
void linkedList<T>::insert(T value){
    std::shared_ptr<Node> temp = std::make_shared<Node>(value);

    if (this->isEmpty()){
        head = std::move(temp);
    } else {
        temp->next = std::move(head);
        head = std::move(temp);
    }
}

template <class T>
bool linkedList<T>::remove(T key){
    if (head == nullptr) {
        return false;
    }

    if (head->value == key){
        auto key_node = head.get();
        head = head->next;
//        delete key_node;
        return true;
    }

    Node *current = head.get();
    while(current->next != nullptr){
        if(current->next->value == key){
            auto key_node = current->next.get();
            current->next = std::move(current->next->next);
//            delete key_node;
            return true;
        }
        current = current->next.get();
    }
    return false;
}

template <class T>
std::shared_ptr<typename linkedList<T>::Node> linkedList<T>::search(T key){

    if(head == nullptr){
        throw std::underflow_error("tried searching through empty list");
    }


    Node* current = head.get();
//    std::weak_ptr<Node> current = head;

    if(head->value == key){
        return head;
    }

    while(current->next != nullptr){
        if(current->next->value == key){
            return current->next;
        }
        current = current->next.get();
    }
    return nullptr;
}

template <class T>
bool linkedList<T>::isEmpty(){
    return head == nullptr;
}

template<typename T>
linkedList<T>* linkedList<T>::merge(linkedList<T>* list) {
    if (head == nullptr) {
        head = list->head;
        return list;
    }
    if (list->head == nullptr) {
        return this;
    }

    Node* current = head.get();

    while(current->next != nullptr){
        current = current->next.get();
    }
    current->next = list->head;

    return this;
}

template<typename T>
void linkedList<T>::print() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        std::cout<< head->value <<std::endl;
        return;
    }

    Node* current = head.get();

    while(current->next != nullptr){
        std::cout<< current->value << std::endl;
        current = current->next.get();
    }
    std::cout<< current->value <<std::endl;
}
