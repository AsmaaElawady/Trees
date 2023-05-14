#include "Manager.h"
//#include "MaxHeap.cpp"
//#include "MinHeap.cpp"
//#include "AVL.cpp"
//#include "BST.cpp"

#include <bits/stdc++.h>

using namespace std;


void Manager::openFile()
{
    fstream file;
    file.open("students.txt", ios::in);
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

/////////////////////////////////////////////////////////

void Manager::mainMenu()
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

/////////////////////////////////////////////////////////

void Manager::BSTMenu()
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
            bst.printDepartment(students);
        }
        else if(choice == 5)
        {
            mainMenu();
        }
    }
}

/////////////////////////////////////////////////////////

void Manager::AVLmenu()
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
                     for(int i = 0 ; i<students.size();i++)
                        {
                            if(students[i].getId() == id)
                            {
                                students.erase(students.begin()+i);
                            }
                        }
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
                Atree.printDepartment(students);
                break;
            }

            case 5:
                mainMenu();
        }
    }
    while(choice != 5);
}

//////////////////////////////////////////////////////////////

void Manager::MinMenu(){
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

void Manager::MaxMenu(){
    int choice = 0;
    for (int i = 0; i < students.size(); ++i)
    {
        MP.insert(students[i]);
    }
    while(choice != 3){
        cout << "\n^^^^^^^^MAX HEAP^^^^^^^^\n";
        cout << "Choose one of the following options:\n"
                "1. Add student\n"
                "2. Print All (sorted by gpa)\n"
                "3. Return to main menu\n";;
        cout << "Choose number: ";
        cin >> choice;
        if(choice == 1){
            Student st;
            st = MP.addStudent();
            students.push_back(st);
        }
        else if(choice == 2){
            MP.print(MP);
            MP.printDepartment(MP);
        }else if(choice == 3){
            mainMenu();
        }
    }
}
