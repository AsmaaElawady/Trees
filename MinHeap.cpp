#include "MinHeap.h"
#include "node.cpp"
#include "Student.cpp"
#include <bits/stdc++.h>

using namespace std;

// Note:
// -> (i-1)/2 is the index of the parent node.
// -> (2*i + 1) is the index of the left child.
// -> (2*i + 2) is the index of the right child.

// default constructor.
MinHeap::MinHeap(){
    capacity = 0;
    size = 0;
    arr = new double[capacity];
}

MinHeap::MinHeap(int cap){
    capacity = cap;
    size = 0;
    arr = new double[capacity];
}

// to get the index of parent node of node at index i.
int MinHeap::parent(int i){
    if(i == 0){
        return i;
    }
    return (i-1)/2;
}

// to get the index of left child of node at index i.
int MinHeap::left(int i){
    return 2*i+1;
}

// to get the index of right child of node at index i.
int MinHeap::right(int i){
    return 2*i+2;
}

void MinHeap::minHeapify(int i){
    // get the index of the left child of current node.
    int l = left(i);
    // get the index of the right child of current node.
    int r = right(i);

    int smallest = i;
    if(l < size && arr[l] < arr[smallest])
        smallest = l;

    if(r < size && arr[r] < arr[smallest])
        smallest = r;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minHeapify(parent(i));
    }
}

void MinHeap::insert(double i){
    if(size == capacity){
        cout << "Heap is Full\n";
        return;
    }

    // insert the new element at the end of the tree.
    int sz = size;
    arr[size++] = double(i);

    // now call heapify to ensure that the minHeap properties not violated.
    if(sz != 0){
        minHeapify(parent(sz));
    }

}

void MinHeap::printMinHeap(){
    double sortedArr[size];
    // fill the new array with the elements of the real array which includes tree nodes.
    for (int i = 0; i < size; ++i) {
        sortedArr[i] = arr[i];
    }
    int minIndx;
    int i;
    for (i = 0; i < size-1; ++i) {
        minIndx = i;
        for (int j = i + 1; j < size; ++j) {
            if (sortedArr[j] < sortedArr[minIndx])
                minIndx = j;
        }
        swap(sortedArr[i], sortedArr[minIndx]);
    }

    for (int j = 0; j < size; ++j) {
        cout << sortedArr[j] << " ";
    }
    cout << endl;
}

void MinHeap::print(){
    for (int j = 0; j < size; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;
}


Student MinHeap::addStudent(){
    Student st;
    int id;
    cout << "Enter ID: ";
    cin >> id;
    string name, dep;
    double gpa;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << "Enter Department: ";
    cin >> dep;
    st.setId(id);
    st.setName(name);
    st.setGpa(gpa);
    st.setDepartment(dep);
    insert(st.getGpa());
    cout << "The Student is Added.\n";
    return st;
}








