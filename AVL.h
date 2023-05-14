#ifndef DATASTRUCTURES_AVL_H
#define DATASTRUCTURES_AVL_H


#include <bits/stdc++.h>
#include "Student.cpp"

using namespace std;

class AVLNode{
public:
    int info;
    AVLNode* leftLink;
    AVLNode* rightLink;

    AVLNode();

    AVLNode(int in);
};

class AVLTree{
public:
    AVLNode* root;

    AVLTree();

    bool isEmpty();

    int height(AVLNode* r);

    int calcBalanceF(AVLNode* node);

    AVLNode* rotateRight(AVLNode* root);

    AVLNode* rotateLeft(AVLNode* root);

    AVLNode* insertNewNode(AVLNode* r, AVLNode* newnode);

    void insertNode(int item);

    AVLNode* getMin(AVLNode* node);

    AVLNode* deleteNode(AVLNode* r, int item);

    void printPreorder(AVLNode * r); //(current node, Left, Right)

    // Stores inorder traversal of the AVLTree
    void storeSorted(AVLNode* root, int arr[], int& i);

    // This function sorts arr[0..n-1] using Tree Sort by id
    void treeSort(vector<Student> &students, int n);

    void printPostorder(AVLNode * r);

    AVLNode * searchForNode(int item);

    Student addStudent();
    
    void printDepartment(vector<Student> &students);
};


#endif //DATASTRUCTURES_AVL_H
