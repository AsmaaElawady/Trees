#include "Student.h"
#pragma once
#include <bits/stdc++.h>


int Student::getId() const
{
    return id;
}

void Student::setId(int id)
{
    Student::id = id;
}

const string& Student::getName() const
{
    return name;
}

void Student::setName(const string &name)
{
    Student::name = name;
}

double Student::getGpa() const
{
    return gpa;
}

void Student::setGpa(double gpa)
{
    Student::gpa = gpa;
}

const string& Student::getDepartment() const
{
    return department;
}

void Student::setDepartment(const string &department)
{
    Student::department = department;
}

