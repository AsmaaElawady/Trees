#ifndef DATASTRUCTURES_MINHEAP_H
#define DATASTRUCTURES_MINHEAP_H

#include "Student.cpp"

class MinHeap
{
private:
    double *arr; // include the nodes of the MinHeap (GPAs).
    int capacity;
    int size;
    vector<Student> myStudents;
    map<string, int> departments;

public:
    // default constructor.
    MinHeap();

    MinHeap(int cap, vector<Student> students);

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

    void addStudent();

    void printDepartments();

    void addDepartment(string dep);

    void sortStudents();
};

#endif // DATASTRUCTURES_MINHEAP_H
