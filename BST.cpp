#include "BST.h"
#include "node.h"
#include "Student.cpp"
#include <bits/stdc++.h>

using namespace std;


//default constructor.
BST::BST() {
    root = NULL;
}

// returns pointer to the last node, because we do not need to start from root each time.
node* BST::insertNode(node *r, int item) {
    // if tree is empty.
    if (r == NULL) {
        node *newNode = new node();
        newNode->data = item;
        newNode->left = NULL;
        newNode->right = NULL;
        r = newNode;
    }

    //if tree is not empty.
    //if the new item is less than last node, insert the new item to the left of this node.
    else if (item < r->data) {
        r->left = insertNode(r->left, item);
    }

    //if the new item is greater than last node, insert the new item to the right of this node.
    else {
        r->right = insertNode(r->right, item);
    }
    return r;
}

void BST::insertNode(int item) {
    root = insertNode(root, item);
}

// print pre-order: root - left - right.
void BST::printTreePre(node *r) {
    if (r == NULL) {
        return;
    }
    cout << r->data << " ";
    printTreePre(r->left);
    printTreePre(r->right);
}

// find max element in tree.
node* BST::findMax(node *r) {
    //check empty.
    if (r == NULL) {
        return NULL;
    }
        // go deep to the most right node (it is the max node)
    else if (r->right == NULL)
        return r;
    else {
        return findMax(r->right);
    }
}

node* BST::deleteNode(node *r, int key) {
    if (r == NULL) {
        return NULL;
    }
    if (key < r->data)
        r->left = deleteNode(r->left, key);
    else if (key > r->data)
        r->right = deleteNode(r->right, key);
        //key is the root(leaf node, has one child, has two children.
    else {
        //check leaf node.
        if (r->right == NULL && r->left == NULL)
            r = NULL;
            //check one child on the right.
        else if (r->left == NULL && r->right != NULL) {
            r->data = r->right->data;
            r = r->right;
        }
            //check one child on the left.
        else if (r->left != NULL && r->right == NULL) {
            r->data = r->left->data;
            r = r->left;
        }
            //node has two children.
        else {
            //replace node with max node in the left
            node *max = findMax(r->left);
            r->data = max->data;
            r->left = deleteNode(r->left, max->data);
        }
    }
    return r;
}

void BST::deleteStudent(int id) {
    root = deleteNode(root, id);
}

node* BST::search(node *r, int key) {
    // if tree is empty.
    if (r == NULL) {
        return NULL;
    } else if (r->data == key) {
        return r;
    } else if (key < r->data) {
        return search(r->left, key);
    } else {
        return search(r->right, key);
    }
}

bool BST::search(int key) {
    node *result = search(root, key);
    if (result == NULL)// element not found.
        return false;
    else
        return true;
}

Student BST::addStudent() {
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
    insertNode(st.getId());
    cout << "The Student is Added.\n";
    return st;
}

// Stores inorder traversal of the BST
void BST::storeSorted(node *root, int arr[], int &i) {
    if (root != NULL) {
        storeSorted(root->left, arr, i);
        arr[i++] = root->data;
        storeSorted(root->right, arr, i);
    }
}

// This function sorts arr[0..n-1] using Tree Sort by id
void BST::treeSort(vector<Student> &students, int n) {
    int *arr = new int[n];
    int i = 0;
    storeSorted(root, arr, i);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < students.size(); ++i) {
            if (students[i].getId() == arr[j]) {
                cout << "[" << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getGpa()
                     << ", " << students[i].getDepartment() << "]\n";
                break;
            }
        }
    }
}
