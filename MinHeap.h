#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include "Student.cpp"

class MinHeap{
private:
    double *arr; // include the nodes of the MinHeap (GPAs).
    int capacity;
    int size;

public:
    // default constructor.
    MinHeap();

    MinHeap(int cap);

    // to get the index of parent node of node at index i.
    int parent(int i);

    // to get the index of left child of node at index i.
    int left(int i);

    // to get the index of right child of node at index i.
    int right(int i);

    void minHeapify(int i);

    void insert(double i);

    void printMinHeap();

    void print();

    Student addStudent();
};


#endif //DATASTRUCTURES_MINHEAP_H
