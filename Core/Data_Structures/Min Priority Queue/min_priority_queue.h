#ifndef MIN_PRORITY_QUEUE_H_
#define MIN_PRORITY_QUEUE_H_

template <typename T>
class MinPriorityQueue
{
private:
    vector<T> heap;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);

public:
    BHeap() {}
    void insert(T element);
    void deleteMin();
    T extractMin();
    void showHeap();
    int size();
};

#endif /* MIN_PRORITY_QUEUE_H_ */