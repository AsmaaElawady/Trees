#ifndef DATASTRUCTURES_MAXHEAP_H
#define DATASTRUCTURES_MAXHEAP_H

#include <bits/stdc++.h>
#include "Student.cpp"

using namespace std;

class MaxHeap
{
private:
    vector<Student> myStudents;

public:
    vector<Student> heap_;

    MaxHeap(vector<Student> students);

    void insert(Student s);

    Student extractMax();

    bool isEmpty();

    void heapifyUp(int index);

    void heapifyDown(int index);

    void addStudent();

    void print(MaxHeap studentHeap);

    void printDepartment(MaxHeap studentHeap);
};

#endif // DATASTRUCTURES_MAXHEAP_H
