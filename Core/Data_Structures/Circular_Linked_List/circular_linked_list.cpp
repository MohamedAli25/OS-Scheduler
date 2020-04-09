/*
#include "circular_linked_list.h"

template <typename T>
void CircularLinkedList<T>::add(T value)
{
    if (root == nullptr)
    {
        root = new CLLNode<T>(value);
    }
    else
    {
        CLLNode<T> *node = new CLLNode<T>(value);
        root->previous->next = node;
        node->previous = root->previous;
        node->next = root;
        root->previous = node;
    }
    linkedListSize++;
}

template <typename T>
CLLNode<T> *CircularLinkedList<T>::removePtr(CLLNode<T> *node)
{
    node->next->previous = node->previous;
    node->previous->next = node->next;
    linkedListSize--;
    CLLNode<T> *result;
    if (linkedListSize == 0)
    {
        root = result = nullptr;
    }
    else
    {
        result = node->next;
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
T *CircularLinkedList<T>::getRoot()
{
    return root;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (root != nullptr)
    {
        this->removePtr(root);
    }
}
*/
