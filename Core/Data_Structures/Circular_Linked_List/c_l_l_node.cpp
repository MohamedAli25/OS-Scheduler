#include "c_l_l_node.h"

template <typename T>
CLLNode<T>::CLLNode(T value) : value{value}, next{nullptr}, previous{nullptr}{
}

template <typename T>
CLLNode<T>::CLLNode(T value, CLLNode *previous, CLLNode *next) : value{value}, previous{previous}, next{next}{
}

template <typename T>
T& CLLNode<T>::getValue(){
    return value;
}

template <typename T>
void CLLNode<T>::setValue(T value){
    this->value = value;
}
