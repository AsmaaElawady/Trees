#ifndef DATASTRUCTURES_MAXHEAP_H
#define DATASTRUCTURES_MAXHEAP_H

#include <bits/stdc++.h>
#include "Student.cpp"

using namespace std;

class MaxHeap {
public:
    vector<Student> heap_;
    //MaxHeap() {}

    void insert(Student s);

    Student extractMax();

    bool isEmpty();

    void heapifyUp(int index);

    void heapifyDown(int index);

    Student addStudent();

    void print(MaxHeap studentHeap);
};

#endif //DATASTRUCTURES_MAXHEAP_H
