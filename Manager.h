#ifndef DATASTRUCTURES_MANAGER_H
#define DATASTRUCTURES_MANAGER_H


#include "MaxHeap.cpp"
#include "MinHeap.cpp"
#include "AVL.cpp"
#include "BST.cpp"

#include <bits/stdc++.h>

using namespace std;


class Manager{
public:
    vector<Student> students;
    BST bst;
    AVLTree Atree;
    MaxHeap MP;

    void openFile();

    void mainMenu();

    void BSTMenu();

    void AVLmenu();

    void MinMenu();

    void MaxMenu();
};


#endif //DATASTRUCTURES_MANAGER_H
