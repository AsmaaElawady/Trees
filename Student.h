#ifndef DATASTRUCTURES_STUDENT_H
#define DATASTRUCTURES_STUDENT_H

#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

class Student{
private:
    int id;
    string name;
    double gpa;
    string department;

public:
    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    double getGpa() const;

    void setGpa(double gpa);

    const string &getDepartment() const;

    void setDepartment(const string &department);

};

using namespace std;

#endif //DATASTRUCTURES_STUDENT_H
