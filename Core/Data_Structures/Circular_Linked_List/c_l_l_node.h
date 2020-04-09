#ifndef C_L_L_NODE_H_
#define C_L_L_NODE_H_

template <typename T>
class CLLNode
{
private:
    T value;
    CLLNode<T> *previous = nullptr;
    CLLNode<T> *next = nullptr;

public:
    CLLNode(T value);
    CLLNode(T value, CLLNode *previous, CLLNode *next);
    T& getValue();
    void setValue(T value);
    CLLNode<T>* getNext();
    void setNext(CLLNode<T>* next);
    CLLNode<T>* getPrevious();
    void setPrevious(CLLNode<T>* previous);
};

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

template <typename T>
CLLNode<T>* CLLNode<T>::getNext(){
    return next;
}

template <typename T>
void CLLNode<T>::setNext(CLLNode<T>* next){
    this->next = next;
}

template <typename T>
CLLNode<T>* CLLNode<T>::getPrevious(){
    return previous;
}

template <typename T>
void CLLNode<T>::setPrevious(CLLNode<T>* previous){
    this->previous = previous;
}

#endif /* C_L_L_NODE_H_ */
