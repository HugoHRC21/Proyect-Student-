#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>
#include <vector>
#include <Grade.h>
#include <fstream>
#include <iostream>

class Student : public Person {
private:
    vector<Grade> grades;

public:
    Student(string& name, int id, const string& email, const string& password);
    Student(const char *name, int id);

    void showInformation() const override;
    void addGrade(const Grade& grade);
    void consultGrades();

    vector<Grade> getGrades();
    void setGrade(const Grade grade);

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);


};

#endif