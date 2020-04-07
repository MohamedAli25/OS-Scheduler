#ifndef C_L_L_NODE_H_
#define C_L_L_NODE_H_

template <typename T>
class CLLNode
{
private:
    T value;
    CLLNode *previous = nullptr;
    CLLNode *next = nullptr;

public:
    CLLNode(T value);
    CLLNode(T value, CLLNode *previous, CLLNode *next);
    T& getValue();
    void setValue(T value);
};

#endif /* C_L_L_NODE_H_ */
