#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    int id;
    string name;
    double gpa;
    string department;

public:
    int getId() const
    {
        return id;
    }

    void setId(int id)
    {
        Student::id = id;
    }

    const string &getName() const
    {
        return name;
    }

    void setName(const string &name)
    {
        Student::name = name;
    }

    double getGpa() const
    {
        return gpa;
    }

    void setGpa(double gpa)
    {
        Student::gpa = gpa;
    }

    const string &getDepartment() const
    {
        return department;
    }

    void setDepartment(const string &department)
    {
        Student::department = department;
    }

};

class node
{
public:
    int data;
    node* left;
    node* right;

    //default constructor
    node()
    {
        data = 0;
        left = right = NULL;
    }
};

class BST
{
public:
    //pointer refers to the first element in the tree.
    node* root;

    //default constructor.
    BST()
    {
        root = NULL;
    }

    // returns pointer to the last node, because we do not need to start from root each time.
    node* insertNode(node* r, int item)
    {
        // if tree is empty.
        if(r == NULL)
        {
            node* newNode = new node();
            newNode->data = item;
            newNode->left = NULL;
            newNode->right = NULL;
            r = newNode;
        }

            //if tree is not empty.
            //if the new item is less than last node, insert the new item to the left of this node.
        else if(item < r->data)
        {
            r -> left = insertNode(r->left, item);
        }

            //if the new item is greater than last node, insert the new item to the right of this node.
        else
        {
            r -> right = insertNode(r->right, item);
        }
        return r;
    }

    void insertNode(int item)
    {
        root = insertNode(root, item);
    }

    // print pre-order: root - left - right.
    void printTreePre(node* r)
    {
        if(r == NULL)
        {
            return;
        }
        cout << r->data << " ";
        printTreePre(r->left);
        printTreePre(r->right);
    }

    // find max element in tree.
    node* findMax(node* r)
    {
        //check empty.
        if(r == NULL)
        {
            return NULL;
        }
            // go deep to the most right node (it is the max node)
        else if(r->right == NULL)
            return r;
        else
        {
            return findMax(r->right);
        }
    }

    node* deleteNode(node* r, int key)
    {
        if(r == NULL)
        {
            return NULL;
        }
        if(key < r->data)
            r->left = deleteNode(r->left, key);
        else if(key > r->data)
            r->right = deleteNode(r->right, key);
            //key is the root(leaf node, has one child, has two children.
        else
        {
            //check leaf node.
            if(r->right == NULL && r->left == NULL)
                r = NULL;
                //check one child on the right.
            else if(r-> left == NULL && r-> right != NULL)
            {
                r->data = r->right->data;
                r = r->right;
            }
                //check one child on the left.
            else if(r-> left != NULL && r-> right == NULL)
            {
                r->data = r->left->data;
                r = r->left;
            }
                //node has two children.
            else
            {
                //replace node with max node in the left
                node* max = findMax(r->left);
                r->data = max->data;
                r-> left = deleteNode(r->left, max->data);
            }
        }
        return r;
    }

    void deleteStudent(int id)
    {
        root = deleteNode(root, id);
    }

    node* search(node* r, int key)
    {
        // if tree is empty.
        if(r == NULL)
        {
            return NULL;
        }
        else if(r->data == key)
        {
            return r;
        }
        else if(key < r->data)
        {
            return search(r->left, key);
        }
        else
        {
            return search(r->right, key);
        }
    }

    bool search(int key)
    {
        node* result = search(root, key);
        if(result == NULL)// element not found.
            return false;
        else
            return true;
    }

    Student addStudent()
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
        insertNode(st.getId());
        cout << "The Student is Added.\n";
        return st;
    }

    // Stores inorder traversal of the BST
    void storeSorted(node* root, int arr[], int& i)
    {
        if (root != NULL)
        {
            storeSorted(root->left, arr, i);
            arr[i++] = root->data;
            storeSorted(root->right, arr, i);
        }
    }

// This function sorts arr[0..n-1] using Tree Sort by id
    void treeSort(vector<Student> &students, int n)
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






};

class AVLNode
{
public:
    int info;
    AVLNode* leftLink;
    AVLNode* rightLink;
    AVLNode()
    {
        info = 0;
        leftLink = nullptr;
        rightLink = nullptr;
    }
    AVLNode(int in)
    {
        info = in;
        leftLink = nullptr;
        rightLink = nullptr;
    }
};
class AVLTree
{
public:

    AVLNode* root;

    AVLTree()
    {
        root = nullptr;
    }

    bool isEmpty()
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
    int height(AVLNode* r)
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
    int calcBalanceF(AVLNode* node)
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

    AVLNode* rotateRight(AVLNode* root)
    {
        AVLNode* temp = root->leftLink;
        AVLNode* temp2 = temp->rightLink;

        temp->rightLink = root;
        root->leftLink = temp2;
        return temp;
    }

    AVLNode* rotateLeft(AVLNode* root)
    {
        AVLNode*temp = root->rightLink;
        AVLNode*temp2 = temp->leftLink;

        root->leftLink = temp;
        temp->rightLink = temp2;
        return root;

    }

    AVLNode* insertNewNode(AVLNode* r, AVLNode* newnode)
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



    void insertNode(int item)
    {
        AVLNode * newnode = new AVLNode();
        newnode -> info = item;
        root = insertNewNode(root, newnode);
    }

    AVLNode* getMin(AVLNode* node)
    {
        AVLNode* temp = node;
        while(temp->leftLink!= nullptr)
        {
            temp = temp->leftLink;
        }
        return temp;
    }


    AVLNode* deleteNode(AVLNode* r, int item)
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
/////////////////////////////////////////////////////////////////////////

    void printPreorder(AVLNode * r) //(current node, Left, Right)
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
    void storeSorted(AVLNode* root, int arr[], int& i)
    {
        if (root != NULL)
        {
            storeSorted(root->leftLink, arr, i);
            arr[i++] = root->info;
            storeSorted(root->rightLink, arr, i);
        }
    }


// This function sorts arr[0..n-1] using Tree Sort by id
    void treeSort(vector<Student> &students, int n)
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


    void printPostorder(AVLNode * r) //(Left, Right, Root)
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


    AVLNode * searchForNode(int item)
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
    Student addStudent()
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

};


// Note:
// -> (i-1)/2 is the index of the parent node.
// -> (2*i + 1) is the index of the left child.
// -> (2*i + 2) is the index of the right child.

class MinHeap{
private:
    double *arr; // include the nodes of the MinHeap (GPAs).
    int capacity;
    int size;

public:
    // default constructor.
    MinHeap(){
        capacity = 0;
        size = 0;
        arr = new double[capacity];
    }

    MinHeap(int cap){
        capacity = cap;
        size = 0;
        arr = new double[capacity];
    }

    // to get the index of parent node of node at index i.
    int parent(int i){
        if(i == 0){
            return i;
        }
        return (i-1)/2;
    }

    // to get the index of left child of node at index i.
    int left(int i){
        return 2*i+1;
    }

    // to get the index of right child of node at index i.
    int right(int i){
        return 2*i+2;
    }

    void minHeapify(int i){
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

    void insert(double i){
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

    void printMinHeap(){
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

    void print(){
        for (int j = 0; j < size; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    Student addStudent(){
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
};


////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
class MaxHeap {
public:
    vector<Student> heap_;
    //MaxHeap() {}

    void insert(Student s) {
        heap_.push_back(s);
        heapifyUp(heap_.size() - 1);
    }

    Student extractMax() {
        Student max = heap_[0];
        heap_[0] = heap_[heap_.size() - 1];
        heap_.pop_back();
        heapifyDown(0);
        return max;
    }

    bool isEmpty() { return heap_.empty(); }



    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap_[index].getGpa() > heap_[parentIndex].getGpa()) {
                std::swap(heap_[index], heap_[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (index < heap_.size()) {
            int maxIndex = index;
            int leftChildIndex = index * 2 + 1, rightChildIndex = index * 2 + 2;
            if (leftChildIndex < heap_.size() &&
                heap_[leftChildIndex].getGpa() > heap_[maxIndex].getGpa()) {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < heap_.size() &&
                heap_[rightChildIndex].getGpa() > heap_[maxIndex].getGpa()) {
                maxIndex = rightChildIndex;
            }
            if (index != maxIndex) {
                swap(heap_[index], heap_[maxIndex]);
                index = maxIndex;
            } else {
                break;
            }
        }
    }
    Student addStudent(){
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
        insert(st);
        cout << "The Student is Added.\n";
        return st;
    }
    void print(MaxHeap studentHeap){
        while (!studentHeap.isEmpty()) {
            Student s = studentHeap.extractMax();
            cout << "[" << s.getId() << ", " << s.getName() << ", " << s.getGpa() << ", "
                 << s.getDepartment() << "]\n";
        }
    }

};

////////////////////////////////////////////////////////////
class Manager
{
public:
    vector<Student> students;
    BST bst;
    AVLTree Atree;
    MaxHeap MP;

    void openFile()
    {
        fstream file;
        file.open("C:\\Users\\Dell\\CLionProjects\\DataStructures\\students.txt", ios::in);
        if (file.is_open())
        {
            string line;
            // Read data from the file object and put it into a string.
            getline(file, line);
            int size = stoi(line);
            for (int j = 0; j < size; ++j)
            {
                Student st;
                getline(file, line);
                st.setId(stoi(line));
                getline(file, line);
                st.setName(line);
                getline(file, line);
                st.setGpa(stod(line));
                getline(file, line);
                st.setDepartment(line);
                students.push_back(st);
            }
            // Close the file object.
            file.close();
        }
    }

    void mainMenu()
    {
        int choice;
        cout << "Choose Data Structure: \n"
                "1. BST.\n"
                "2. AVL.\n"
                "3. Min Heap.\n"
                "4. Max Heap.\n"
                "5. Exit Program.\n";
        cout << "Choose number: ";
        cin >> choice;
        if(choice == 1)
        {
            BSTMenu();
        }
        else if(choice == 2)
        {
            AVLmenu();
        }else if(choice == 3)
        {
            MinMenu();
        }
        else if(choice==4){
            MaxMenu();
        }
        else if(choice == 5)
            return;
    }

    void BSTMenu()
    {
        int choice = 0;
        for (int i = 0; i < students.size(); ++i)
        {
            bst.insertNode(students[i].getId());
        }
        while(choice != 5)
        {
            cout << "\n^^^^^^^^Binary Search Tree^^^^^^^^\n";
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu\n";
            cout << "Choose number: ";
            cin >> choice;
            if(choice == 1)
            {
                Student st;
                st = bst.addStudent();
                students.push_back(st);
            }
            else if(choice == 2)
            {
                bool found = true;
                int id;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Tree Before Deletion: \n";
                bst.printTreePre(bst.root);
                cout << endl;
                for (int i = 0; i < students.size(); ++i)
                {
                    if(students[i].getId() == id)
                    {
                        found = true;
                        cout << "Student is found.\n";
                        cout << "[" << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getGpa() << ", " << students[i].getDepartment() << "]\n";
                        students.erase(students.begin()+i);

                        cout << endl;
                        break;
                    }
                    else
                    {
                        found = false;
                    }
                }
                if(found)
                {
                    bst.deleteStudent(id);
                    cout << "Student is deleted.\n";
                    cout << "Tree After Deletion: \n";
                    bst.printTreePre(bst.root);
                }
                else
                {
                    cout << "Student is not found.\n";
                }
            }
            else if(choice == 3)
            {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                bool found = bst.search(id);
                if(found)
                {
                    cout << "Student is found.\n";
                    for (int i = 0; i < students.size(); ++i)
                    {
                        if (students[i].getId() == id)
                        {
                            cout << "[" << students[i].getId() << ", " << students[i].getName() << ", "
                                 << students[i].getGpa() << ", " << students[i].getDepartment() << "]\n";
                            cout << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Student not found.\n";
                }
            }
            else if(choice == 4)
            {
                //bst.printTreePre(bst.root);
                bst.treeSort(students, students.size());


            }
            else if(choice == 5)
            {
                mainMenu();
            }
        }
    }
/////////////////////////////////////////////////////////
    void AVLmenu()
    {
        int choice;

        for (int i = 0; i < students.size(); ++i)
        {
            AVLNode * newnode = new AVLNode();
            newnode -> info = students[i].getGpa();
            Atree.insertNewNode(Atree.root,newnode);
        }
        for (int i = 0; i < students.size(); ++i)
        {
            AVLNode * newnode = new AVLNode();
            newnode -> info = students[i].getId();
            //     cout<<students[i].getId()<<endl;
            Atree.root=  Atree.insertNewNode(Atree.root,newnode);
        }

        do
        {
            cout << "\n^^^^^^^^AVL Tree^^^^^^^^\n";
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu\n";
            cout << "Choose number: ";

            cin>> choice;
            switch(choice)
            {
                case 1:
                {
                    Student newStud;
                    newStud = Atree.addStudent();
                    students.push_back(newStud);
                    break;
                }

                case 2:
                {
                    int id;
                    cout<< "Enter ID to remove : ";
                    cin>>id;
                    //
                    AVLNode* newnode = new AVLNode();
                    newnode = Atree.searchForNode(id);
                    if(newnode != nullptr)
                    {
                        Atree.root = Atree.deleteNode(Atree.root, id);
                        cout<< "Student with ID = " << id << " is deleted"<<endl;
                    }
                    else
                    {
                        cout<< "Sorry, this student doesn't exist"<<endl;
                    }
                    break;
                }


                case 3:
                {
                    cout << "SEARCH" << endl;
                    int id;
                    cout << "Enter ID to Search For ";
                    cin >> id;
                    AVLNode * newnode = new AVLNode();
                    newnode = Atree.searchForNode(id);
                    if (newnode != NULL)
                    {
                        cout << "Value found" << endl;
                    }
                    else
                    {
                        cout << "Value NOT found" << endl;
                    }
                    break;
                }

                case 4:
                {
                    //  cout<< "will print all students";
                    //  Atree.printPreorder(Atree.root);
                    //Atree.printPreorder(Atree.root);
                    Atree.treeSort(students, students.size());
                    break;
                }

                case 5:
                    mainMenu();

            }
        }
        while(choice != 5);
    }
    //////////////////////////////////////////////////////////////

    void MinMenu(){
        MinHeap mh(200);
        int choice = 0;
        for (int i = 0; i < students.size(); ++i) {
            mh.insert(students[i].getGpa());
        }
        while(choice != 3){
            cout << "\n^^^^^^^^Min HEAP^^^^^^^^\n";
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)\n"
                    "3. Return to main menu\n";
            cout << "Choose number: ";
            cin >> choice;
            if(choice == 1){
                Student st;
                st = mh.addStudent();
                students.push_back(st);
            }
            else if(choice == 2){
                mh.printMinHeap();
            }else if(choice == 3){
                mainMenu();
            }
        }
    }



    void MaxMenu(){
        int choice = 0;
        for (int i = 0; i < students.size(); ++i)
        {
            MP.insert(students[i]);
        }
        while(choice != 2){
            cout << "\n^^^^^^^^MAX HEAP^^^^^^^^\n";
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Print All (sorted by gpa)\n";
            cout << "Choose number: ";
            cin >> choice;
            if(choice == 1){
                Student st;
                st = MP.addStudent();
                students.push_back(st);
            }
            else if(choice == 2){
                MP.print(MP);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////



};

int main()
{
    Manager mng;
    mng.openFile();
    mng.mainMenu();
}
