//
// Created by Gabriel Venezia on 4/23/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <vector>

template<typename T, typename compare>
class Heap {
    std::vector<T> data;
    compare comp;

public:
    Heap() : comp(comp) {}
    int getParentIndex(int child_index);
    int getLeftChildIndex(int parent_index);
    int getRightChildIndex(int parent_index);
    int getMaxChildIndex(int parent_index);

    void ReheapifyUp(int child_index);
    void ReheapifyDown(int parent_index);

    void push(T item);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};

#include "Heap.cpp"

#endif //HEAP_H
