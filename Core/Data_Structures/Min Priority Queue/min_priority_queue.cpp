#include "min_priority_queue.h"

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(bool (*less)(const T &l, const T &r))
{
    this->less = less;
}

template <typename T>
int MinPriorityQueue<T>::size()
{
    return heap.size();
}

template <typename T>
void MinPriorityQueue<T>::insert(T ele)
{
    heap.push_back(ele);
    heapifyup(heap.size() - 1);
}

template <typename T>
void MinPriorityQueue<T>::deleteMin()
{
    if (heap.size() == 0)
    {
        cout << "Heap is Empty" << endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    cout << "Element Deleted" << endl;
}

template <typename T>
T MinPriorityQueue<T>::extractMin()
{
    if (heap.size() == 0)
    {
        return -1;
    }
    else
        return heap.front();
}

template <typename T>
int MinPriorityQueue<T>::l(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}

template <typename T>
int MinPriorityQueue<T>::r(int parent)
{
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}

template <typename T>
int MinPriorityQueue<T>::par(int child)
{
    int p = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return p;
}

template <typename T>
void MinPriorityQueue<T>::heapifyup(int in)
{
    if (in >= 0 && par(in) >= 0 && this->less(heap[in], heap[par(in)]))
    {
        int temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}

template <typename T>
void MinPriorityQueue<T>::heapifydown(int in)
{
    int child = l(in);
    int child1 = r(in);
    if (child >= 0 && child1 >= 0 && this->less(heap[child1], heap[child]))
    {
        child = child1;
    }
    if (child > 0 && this->less(heap[child], heap[in]))
    {
        int t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}

template <typename T>
static bool MinPriorityQueue<T>::less(const T &l, const T &r)
{
    return (l < r);
}

template <typename T>
static bool MinPriorityQueue<T>::compareTo(const T &l, const T &r)
{
    if (l < r)
        return -1;
    else if (l > r)
        return 1;
    return 0
}