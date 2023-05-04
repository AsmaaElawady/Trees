#include <bits/stdc++.h>

using namespace std;

class Student{
private:
    int id;
    string name;
    double gpa;
    string department;

public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Student::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    double getGpa() const {
        return gpa;
    }

    void setGpa(double gpa) {
        Student::gpa = gpa;
    }

    const string &getDepartment() const {
        return department;
    }

    void setDepartment(const string &department) {
        Student::department = department;
    }

};

class node{
public:
    int data;
    node* left;
    node* right;

    //default constructor
    node(){
        data = 0;
        left = right = NULL;
    }
};

class BST {
public:
    //pointer refers to the first element in the tree.
    node* root;

    //default constructor.
    BST(){
        root = NULL;
    }

    // returns pointer to the last node, because we do not need to start from root each time.
    node* insertNode(node* r, int item){
        // if tree is empty.
        if(r == NULL){
            node* newNode = new node();
            newNode->data = item;
            newNode->left = NULL;
            newNode->right = NULL;
            r = newNode;
        }

        //if tree is not empty.
        //if the new item is less than last node, insert the new item to the left of this node.
        else if(item < r->data){
            r -> left = insertNode(r->left, item);
        }

        //if the new item is greater than last node, insert the new item to the right of this node.
        else{
            r -> right = insertNode(r->right, item);
        }
        return r;
    }

    void insertNode(int item){
        root = insertNode(root, item);
    }

    // print pre-order: root - left - right.
    void printTreePre(node* r){
        if(r == NULL){
            return;
        }
        cout << r->data << " ";
        printTreePre(r->left);
        printTreePre(r->right);
    }

    // find max element in tree.
    node* findMax(node* r){
        //check empty.
        if(r == NULL){
            return NULL;
        }
        // go deep to the most right node (it is the max node)
        else if(r->right == NULL)
            return r;
        else{
            return findMax(r->right);
        }
    }

    node* deleteNode(node* r, int key){
        if(r == NULL){
            return NULL;
        }
        if(key < r->data)
            r->left = deleteNode(r->left, key);
        else if(key > r->data)
            r->right = deleteNode(r->right, key);
        //key is the root(leaf node, has one child, has two children.
        else{
            //check leaf node.
            if(r->right == NULL && r->left == NULL)
                r = NULL;
            //check one child on the right.
            else if(r-> left == NULL && r-> right != NULL){
                r->data = r->right->data;
                r = r->right;
            }
            //check one child on the left.
            else if(r-> left != NULL && r-> right == NULL){
                r->data = r->left->data;
                r = r->left;
            }
            //node has two children.
            else{
                //replace node with max node in the left
                node* max = findMax(r->left);
                r->data = max->data;
                r-> left = deleteNode(r->left, max->data);
            }
        }
        return r;
    }

    void deleteStudent(int id){
        root = deleteNode(root, id);
    }

    node* search(node* r, int key){
        // if tree is empty.
        if(r == NULL){
            return NULL;
        }
        else if(r->data == key){
            return r;
        }
        else if(key < r->data){
            return search(r->left, key);
        }
        else{
            return search(r->right, key);
        }
    }

    bool search(int key){
        node* result = search(root, key);
        if(result == NULL)// element not found.
            return false;
        else
            return true;
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
        insertNode(st.getId());
        cout << "The Student is Added.\n";
        return st;
    }

};

class Manager{
public:
    vector<Student> students;
    BST bst;

    void openFile(){
        fstream file;
        file.open("C:\\Users\\Dell\\CLionProjects\\DataStructures\\students.txt", ios::in);
        if (file.is_open()) {
            string line;
            // Read data from the file object and put it into a string.
            getline(file, line);
            int size = stoi(line);
            for (int j = 0; j < size; ++j) {
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

    void mainMenu(){
        int choice;
        cout << "Choose Data Structure: \n"
                "1. BST.\n"
                "2. AVL.\n"
                "3. Min Heap.\n"
                "4. Max Heap.\n"
                "5. Exit Program.\n";
        cout << "Choose number: ";
        cin >> choice;
        if(choice == 1){
            BSTMenu();
        }
        else if(choice == 5)
            return;
    }

    void BSTMenu(){
        int choice = 0;
        for (int i = 0; i < students.size(); ++i) {
            bst.insertNode(students[i].getId());
        }
        while(choice != 5){
            cout << "\n^^^^^^^^Binary Search Tree^^^^^^^^\n";
            cout << "Choose one of the following options:\n"
                    "1. Add student\n"
                    "2. Remove student\n"
                    "3. Search student\n"
                    "4. Print All (sorted by id)\n"
                    "5. Return to main menu\n";
            cout << "Choose number: ";
            cin >> choice;
            if(choice == 1){
                Student st;
                st = bst.addStudent();
                students.push_back(st);
            }
            else if(choice == 2){
                bool found = true;
                int id;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Tree Before Deletion: \n";
                bst.printTreePre(bst.root);
                cout << endl;
                for (int i = 0; i < students.size(); ++i) {
                    if(students[i].getId() == id){
                        found = true;
                        cout << "Student is found.\n";
                        cout << "[" << students[i].getId() << ", " << students[i].getName() << ", " << students[i].getGpa() << ", " << students[i].getDepartment() << "]\n";
                        students.erase(students.begin()+i);

                        cout << endl;
                        break;
                    }else{
                        found = false;
                    }
                }
                if(found){
                    bst.deleteStudent(id);
                    cout << "Student is deleted.\n";
                    cout << "Tree After Deletion: \n";
                    bst.printTreePre(bst.root);
                }else{
                    cout << "Student is not found.\n";
                }
            }else if(choice == 3){
                int id;
                cout << "Enter ID: ";
                cin >> id;
                bool found = bst.search(id);
                if(found){
                    cout << "Student is found.\n";
                    for (int i = 0; i < students.size(); ++i) {
                        if (students[i].getId() == id) {
                            cout << "[" << students[i].getId() << ", " << students[i].getName() << ", "
                                 << students[i].getGpa() << ", " << students[i].getDepartment() << "]\n";
                            cout << endl;
                            break;
                        }
                    }
                }
                else{
                    cout << "Student not found.\n";
                }
            }else if(choice == 4){
                bst.printTreePre(bst.root);
            }
            else if(choice == 5){
                mainMenu();
            }
        }
    }
};

int main(){
    Manager mng;
    mng.openFile();
    mng.mainMenu();

}
