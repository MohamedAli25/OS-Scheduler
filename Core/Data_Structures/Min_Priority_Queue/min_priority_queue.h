#ifndef MIN_PRORITY_QUEUE_H_
#define MIN_PRORITY_QUEUE_H_

#include <vector>

template <typename T>
class MinPriorityQueue
{
private:
    std::vector<T> heap;
    bool (*less)(const T &l, const T &r) = MinPriorityQueue::lessDefault;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);
    // Static Methods
    static bool lessDefault(const T &l, const T &r);
    static bool compareToDefault(const T &l, const T &r);

public:
    MinPriorityQueue();
    MinPriorityQueue(bool (*less)(const T &l, const T &r));
    void insert(T element);
    void deleteMin();
    T &extractMin();
    int size();
};

#endif /* MIN_PRORITY_QUEUE_H_ */
