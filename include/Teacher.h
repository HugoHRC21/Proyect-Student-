#ifndef TEACHER_H
#define TEACHER_H

#include <Person.h>
#include <Student.h>
#include <iostream>
#include <vector>
#include <Grade.h>
#include <fstream>

class Teacher : public Person {
public:
    Teacher(const string& name, int id, const string& email, const string& password);
    Teacher(const char* name, int id, const string& email, const string& password);
    
    void showInformation() const override;
    void assignGrade(Student& student, const Grade& grade);

    friend ostream& operator<<(ostream& os, const Teacher& teacher);
    friend istream& operator>>(istream& is, Teacher& teacher);
};

#endif  