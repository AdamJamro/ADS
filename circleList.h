//
// Created by adame on 3/9/2023.
//

#ifndef LAB1_CIRCLELIST_H
#define LAB1_CIRCLELIST_H

#include <memory>
#include <stdexcept>

template <typename T>
class circleList {
private:
    struct Node;
    std::shared_ptr<Node> head = nullptr;

public:
    void insert(T);
    bool remove(T);
    bool isEmpty();
    std::shared_ptr<Node> search(T);
    circleList<T>* merge(circleList<T>*);
    std::shared_ptr<Node> getHead(){
        return head;
    }
    void print();
    ~circleList();
};


#endif //LAB1_CIRCLELIST_H
