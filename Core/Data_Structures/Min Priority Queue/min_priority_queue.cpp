#include "min_priority_queue.h"

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
void MinPriorityQueue<T>::showHeap()
{
    vector<int>::iterator pos = heap.begin();
    cout << "Heap --> ";
    while (pos != heap.end())
    {
        cout << *pos << " ";
        pos++;
    }
    cout << endl;
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
    if (in >= 0 && par(in) >= 0 && heap[par(in)] > heap[in])
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
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
        child = child1;
    }
    if (child > 0 && heap[in] > heap[child])
    {
        int t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}