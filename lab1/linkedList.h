//
// Created by adame on 3/9/2023.
//

#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H

#include <memory>
#include <stdexcept>

template <typename T>
class linkedList {
    struct Node;
    std::shared_ptr<Node> head = nullptr;
//    std::shared_ptr<Node> current = nullptr;

public:
    void insert(T);
    bool remove(T);
    bool isEmpty();
    std::shared_ptr<Node> search(T);
    //changes first linkedlist
    linkedList<T>* merge(linkedList<T>*);
    std::shared_ptr<Node> getHead(){
        return head;
    }
    void print();

};




#endif //LAB1_LINKEDLIST_H
