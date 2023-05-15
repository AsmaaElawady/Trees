#include "MinHeap.h"
#include "node.cpp"
#include "Student.cpp"
#include <bits/stdc++.h>
#include <map>

using namespace std;

// Note:
// -> (i-1)/2 is the index of the parent node.
// -> (2*i + 1) is the index of the left child.
// -> (2*i + 2) is the index of the right child.

// default constructor.
MinHeap::MinHeap()
{
    capacity = 0;
    size = 0;
    arr = new double[capacity];
}

MinHeap::MinHeap(int cap, vector<Student> students)
{
    capacity = cap;
    size = 0;
    arr = new double[capacity];
    for (size_t i = 0; i < students.size(); i++)
    {
        myStudents.push_back(students[i]);
        addDepartment(students[i].getDepartment());
    }
}

// to get the index of parent node of node at index i.
int MinHeap::parent(int i)
{
    if (i == 0)
    {
        return i;
    }
    return (i - 1) / 2;
}

// to get the index of left child of node at index i.
int MinHeap::left(int i)
{
    return 2 * i + 1;
}

// to get the index of right child of node at index i.
int MinHeap::right(int i)
{
    return 2 * i + 2;
}

void MinHeap::minHeapify(int i)
{
    // get the index of the left child of current node.
    int l = left(i);
    // get the index of the right child of current node.
    int r = right(i);

    int smallest = i;
    if (l < size && arr[l] < arr[smallest])
        smallest = l;

    if (r < size && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(parent(i));
    }
}

void MinHeap::printDepartments()
{
    map<std::string, int>::iterator it = departments.begin();
    while (it != departments.end())
    {
        cout << it->first << " " << it->second << " Students" << endl;
        ++it;
    }
}

void MinHeap::insert(double i)
{
    if (size == capacity)
    {
        cout << "Heap is Full\n";
        return;
    }

    // insert the new element at the end of the tree.
    int sz = size;
    arr[size++] = double(i);

    // now call heapify to ensure that the minHeap properties not violated.
    if (sz != 0)
    {
        minHeapify(parent(sz));
    }
}

void MinHeap::print()
{
    sortStudents();
    for (int i = 0; i < myStudents.size(); i++)
    {
        cout << "[" << myStudents[i].getId() << ", " << myStudents[i].getName() << ", " << myStudents[i].getGpa()
             << ", " << myStudents[i].getDepartment() << "]\n";
    }
    printDepartments();
}

void MinHeap::addStudent()
{
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
    myStudents.push_back(st);
    addDepartment(dep);
    insert(st.getGpa());
    cout << "The Student is Added.\n";
}

void MinHeap::addDepartment(string dep)
{
    auto it = departments.find(dep);

    // if department not found
    if (it == departments.end())
    {
        departments.insert({dep, 1});
    }
    else
    {
        departments[dep]++;
    }
}

void MinHeap::sortStudents()
{
    for (int i = 0; i < myStudents.size() - 1; ++i)
    {
        for (int j = 0; j < myStudents.size() - i - 1; ++j)
        {
            if (myStudents[j].getGpa() > myStudents[j + 1].getGpa())
                swap(myStudents[j], myStudents[j + 1]);
        }
    }
}