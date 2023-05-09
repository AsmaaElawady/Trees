#include "AVL.h"
#include "node.cpp"
#include "Student.cpp"


#include <bits/stdc++.h>

using namespace std;

AVLNode::AVLNode()
{
    info = 0;
    leftLink = nullptr;
    rightLink = nullptr;
}

AVLNode::AVLNode(int in)
{
    info = in;
    leftLink = nullptr;
    rightLink = nullptr;
}






AVLTree::AVLTree(){
    root = nullptr;
}

bool AVLTree::isEmpty()
{
    if(root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int AVLTree::height(AVLNode* r)
{
    if(r == nullptr)
    {
        return -1;
    }
    else
    {
        int lHeight = height(r->leftLink);
        int rHeight = height(r->rightLink);
        return max(rHeight, lHeight)+1;

    }
}

int AVLTree::calcBalanceF(AVLNode* node)
{
    if(node == nullptr)
    {
        return -1;
    }
    else
    {
        return height(node->leftLink) - height(node->rightLink);
    }
}

AVLNode* AVLTree::rotateRight(AVLNode* root)
{
    AVLNode* temp = root->leftLink;
    AVLNode* temp2 = temp->rightLink;

    temp->rightLink = root;
    root->leftLink = temp2;
    return temp;
}

AVLNode* AVLTree::rotateLeft(AVLNode* root)
{
    AVLNode*temp = root->rightLink;
    AVLNode*temp2 = temp->leftLink;

    root->leftLink = temp;
    temp->rightLink = temp2;
    return root;

}

AVLNode* AVLTree::insertNewNode(AVLNode* r, AVLNode* newnode)
{
    if(r == nullptr)
    {
        r = newnode;
        //cout<< "node has been added successfully to root" <<endl;

        return r;
    }


    if(newnode->info < r->info)
    {
        r->leftLink =  insertNewNode(r->leftLink, newnode);
        // cout<< "node has been added successfully" <<endl;

    }
    else if(r->info < newnode->info)
    {

        r->rightLink=   insertNewNode(r->rightLink, newnode);
        //  cout<< "node has been added successfully" <<endl;

    }
    else if(r->info == newnode->info)
    {
        cout<< "AVL structure doesn't support duplicates"<<endl;
        return r;
    }
    return r;

    int bf = calcBalanceF(r);
    // Left Left Case
    if (bf > 1 && newnode -> info < r -> leftLink-> info)
    {
        return rotateRight(r);
    }


    // Right Right Case
    if (bf < -1 && newnode -> info > r -> rightLink -> info)
    {
        return rotateLeft(r);
    }

    // Left Right Case
    if (bf > 1 && newnode -> info > r -> leftLink -> info)
    {
        r -> leftLink = rotateLeft(r -> leftLink);
        return rotateRight(r);
    }

    // Right Left Case
    if (bf < -1 && newnode -> info < r -> rightLink -> info)
    {
        r -> rightLink = rotateRight(r -> rightLink);
        return rotateLeft(r);
    }
    return r;
}

void AVLTree::insertNode(int item)
{
    AVLNode * newnode = new AVLNode();
    newnode -> info = item;
    root = insertNewNode(root, newnode);
}

AVLNode* AVLTree::getMin(AVLNode* node)
{
    AVLNode* temp = node;
    while(temp->leftLink!= nullptr)
    {
        temp = temp->leftLink;
    }
    return temp;
}

AVLNode* AVLTree::deleteNode(AVLNode* r, int item)
{
    if(r == nullptr)
    {
        return r;
    }
    else if(item < r->info)
    {
        r->leftLink = deleteNode(r->leftLink, item);
    }
    else if(item > r->info)
    {
        r->rightLink = deleteNode(r->rightLink, item);
    }
    else
    {
        if(r->leftLink == nullptr) // the node has right child only
        {
            AVLNode* temp = r->rightLink;
            delete r;
            return temp;
        }
        else if(r->rightLink == nullptr)// the node has left child only
        {
            AVLNode* temp = r->leftLink;
            delete r;
            return temp;
        }
        else// the node has 2 children
        {
            AVLNode* temp = getMin(r->rightLink);// either getting the max in left or min in right
            r->info = temp->info;
            r->rightLink = deleteNode(r->rightLink,temp->info);
        }
    }
    // till here the node is deleted
    // next we balance the tree by checking the balance factor of the current root
    // then rotate
    int bf = calcBalanceF(r);
    // if bf == 2 then we deleted from right subtree
    // if bf of left child = -1 means it is LR rotation
    // if bf == -2 then we deleted from left subtree
    // if bf of right child = 1 means it is RL rotation

    if(bf == 2 && calcBalanceF(r->leftLink) >= 0)
    {
        return rotateRight(r);
    }
    else if(bf == 2 && calcBalanceF(r->leftLink) == -1)
    {
        r->leftLink = rotateLeft(r->leftLink);
        return rotateRight(r);
    }
    else if(bf == -2 && calcBalanceF(r->rightLink) <= 0)
    {
        return rotateLeft(r);
    }
    else if(bf == -2 && calcBalanceF(r->rightLink) == 1)
    {
        r->rightLink = rotateRight(r->rightLink);
        return rotateLeft(r);
    }
    return r;

}

void AVLTree::printPreorder(AVLNode * r) //(current node, Left, Right)
{
    if (r == NULL)
    {
        return;
    }

    else
    {
        //cout<< "printing 21";
        /* first print data of node */
        cout << r -> info << " ";
        // cout<< "printing 31";
        /* then recur on left sutree */
        printPreorder(r -> leftLink);
        //cout<< "printing 251";
        /* now recur on right subtree */
        printPreorder(r -> rightLink);
    }
}

// void printInorder(AVLNode * r) //  (Left, current node, Right)
// {
//     if (r == NULL)
//         return;
//     /* first recur on left child */
//     printInorder(r -> leftLink);
//     /* then print the data of node */
//     cout << r -> info << " ";
//     /* now recur on right child */
//     printInorder(r -> rightLink);
// }

// Stores inorder traversal of the AVLTree
void AVLTree::storeSorted(AVLNode* root, int arr[], int& i)
{
    if (root != NULL)
    {
        storeSorted(root->leftLink, arr, i);
        arr[i++] = root->info;
        storeSorted(root->rightLink, arr, i);
    }
}


// This function sorts arr[0..n-1] using Tree Sort by id
void AVLTree::treeSort(vector<Student> &students, int n)
{
    int *arr = new int[n];
    int i = 0;
    storeSorted(root, arr, i);
    for (int j=0; j<n; j++)
    {
        for (int i = 0; i < students.size(); ++i)
        {
            if(students[i].getId() == arr[j])
            {
                cout << "[" << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getGpa() << ", " << students[i].getDepartment() << "]\n";
                break;
            }
        }
    }
}


void AVLTree::printPostorder(AVLNode * r) //(Left, Right, Root)
{
    if (r == NULL)
        return;
    // first recur on left subtree
    printPostorder(r -> leftLink);
    // then recur on right subtree
    printPostorder(r -> rightLink);
    // now deal with the node
    cout << r -> info << " ";
}


AVLNode* AVLTree::searchForNode(int item)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        AVLNode * temp = root;
        while (temp != NULL)
        {
            if (item == temp -> info)
            {
                return temp;
            }
            else if (item < temp -> info)
            {
                temp = temp -> leftLink;
            }
            else
            {
                temp = temp -> rightLink;
            }
        }
        return NULL;
    }
}
/////////
Student AVLTree::addStudent()
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
    insertNode(id);
    cout << "The Student is Added.\n";
    return st;
}
