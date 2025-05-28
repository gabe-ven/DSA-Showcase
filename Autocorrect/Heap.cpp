
#ifndef HEAP_CPP
#define HEAP_CPP

#include "Heap.h"

// returns index of the parent of a given child index
template<typename T, typename compare>
int Heap<T, compare>::getParentIndex(int child_index) {
    return (child_index - 1) / 2;
}

// returns the index of left child of a given parent index
template<typename T, typename compare>
int Heap<T, compare>::getLeftChildIndex(int parent_index) {
    return parent_index * 2 + 1;
}

// returns the index of right child of a given parent index
template<typename T, typename compare>
int Heap<T, compare>::getRightChildIndex(int parent_index) {
    return parent_index * 2 + 2;
}

// return index of child with highest priority
template<typename T, typename compare>
int Heap<T, compare>::getMaxChildIndex(int parent_index) {
    int left = getLeftChildIndex(parent_index);
    int right = getRightChildIndex(parent_index);

    if (left >= data.size()) // no children
        return parent_index;
    if (right >= data.size()) // only left child
        return left;

    // return child with the higher priority
    if (comp(data[right], data[left])) {
        return left;
    } else {
        return right;
    }
}

// restores heap property by moving an element up the tree
template<typename T, typename compare>
void Heap<T, compare>::ReheapifyUp(int child_index) {
    if (child_index == 0) // reached root
        return;
    int parent_index = getParentIndex(child_index);

    // if child has higher priority than parent, swap and continue
    if (comp(data[child_index], data[parent_index])) {
        std::swap(data[parent_index], data[child_index]);
        ReheapifyUp(parent_index); // recursively move up
    }
}

// restores heap property by moving an element down the tree
template<typename T, typename compare>
void Heap<T, compare>::ReheapifyDown(int parent_index) {
    int maxChild = getMaxChildIndex(parent_index);

    // if child has higher priority than parent, swap and continue
    if (maxChild != parent_index && comp(data[maxChild], data[parent_index])) {
        std::swap(data[parent_index], data[maxChild]);
        ReheapifyDown(maxChild); // recursively move down
    }
}

// adds a new item to the heap and restores heap property
template<typename T, typename compare>
void Heap<T, compare>::push(T item) {
    data.push_back(item); // add to end
    ReheapifyUp(data.size() - 1); // restore heap property
}

// removes the top item from the heap and restores heap property
template<typename T, typename compare>
void Heap<T, compare>::pop() {
    if (data.empty())
        return;

    std::swap(data[0], data[data.size() - 1]); // swap root with last item
    data.pop_back(); // remove last item (original root)

    if (!data.empty()) {
        ReheapifyDown(0); // restore heap property from the root
    }
}

// returns the top item from the heap
template<typename T, typename compare>
T Heap<T, compare>::top() const {
    if (data.empty())
        throw std::out_of_range("Heap is empty");
    return data[0];
}

// returns true if the heap is empty
template<typename T, typename compare>
bool Heap<T, compare>::empty() const {
    return data.empty();
}

// returns the number of items in the heap
template<typename T, typename compare>
int Heap<T, compare>::size() const {
    return data.size();
}

#endif // HEAP_CPP
