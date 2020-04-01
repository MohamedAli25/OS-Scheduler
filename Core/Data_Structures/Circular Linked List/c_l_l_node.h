#ifndef C_L_L_NODE_H_
#define C_L_L_NODE_H_

#include "circular_linked_list.h"

template <typename T>
class CLLNode
{
private:
    T value;
    CLLNode *previous;
    CLLNode *next;

public:
    CLLNode(T value);
    CLLNode(T value, CLLNode *previous, CLLNode *next);
    T getValue();
    void setValue(T value);

    friend class CircularLinkedList<T>;
};

#endif /* C_L_L_NODE_H_ */