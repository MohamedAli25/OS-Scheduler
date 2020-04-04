#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include "c_l_l_node.h"

template <typename T>
class CircularLinkedList{
private:
    CLLNode<T> *root = nullptr;
    unsigned long long linkedListSize = 0;

public:
    void add(T value);
    CLLNode<T> *removePtr(CLLNode<T> *node);
    bool isEmpty();
    unsigned long long size();
    void clear();
};

#endif /* CIRCULAR_LINKED_LIST_H_ */
