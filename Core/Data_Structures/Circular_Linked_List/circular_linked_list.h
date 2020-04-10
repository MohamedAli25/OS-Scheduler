#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include "c_l_l_node.h"

template <typename T>
class CircularLinkedList
{
private:
    CLLNode<T> *root = nullptr;
    unsigned long long linkedListSize = 0;

public:
    void add(T value);
    CLLNode<T> *removePtr(CLLNode<T> *node);
    bool isEmpty();
    unsigned long long size();
    void clear();
    CLLNode<T> *getRoot();
    ~CircularLinkedList();
};

template <typename T>
void CircularLinkedList<T>::add(T value)
{
    if (root == nullptr)
    {
        root = new CLLNode<T>(value);
        root->setNext(root);
        root->setPrevious(root);
    }
    else
    {
        CLLNode<T> *node = new CLLNode<T>(value);
        root->getPrevious()->setNext(node);
        node->setPrevious(root->getPrevious());
        node->setNext(root);
        root->setPrevious(node);
    }
    linkedListSize++;
}

template <typename T>
CLLNode<T> *CircularLinkedList<T>::removePtr(CLLNode<T> *node)
{
    node->getNext()->setPrevious(node->getPrevious());
    node->getPrevious()->setNext(node->getNext());
    linkedListSize--;
    CLLNode<T> *result;
    if (linkedListSize == 0)
    {
        root = result = nullptr;
    }
    else
    {
        result = node->getNext();
    }
    delete node;
    return result;
}

template <typename T>
bool CircularLinkedList<T>::isEmpty()
{
    return linkedListSize == 0;
}

template <typename T>
unsigned long long CircularLinkedList<T>::size()
{
    return linkedListSize;
}

template <typename T>
void CircularLinkedList<T>::clear()
{
    while (root != nullptr)
    {
        removePtr(root);
    }
}

template <typename T>
CLLNode<T> *CircularLinkedList<T>::getRoot()
{
    return root;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    clear();
}

#endif /* CIRCULAR_LINKED_LIST_H_ */
