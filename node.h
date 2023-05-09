#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

#include <bits/stdc++.h>

using namespace std;

class node{
public:

    int data;
    node* left;
    node* right;

    node(){
        data = 0;
        left = right = NULL;
    }
};

#endif //DATASTRUCTURES_NODE_H
