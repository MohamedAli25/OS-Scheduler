#include "c_l_l_node.h"

template <typename T>
CLLNode<T>::CLLNode(T value, CLLNode *previous, CLLNode *next) : value{value}, previous{previous}, next{next}
{
}