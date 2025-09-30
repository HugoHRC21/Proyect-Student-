#include <Teacher.h>
#include <fstream>
#include <iostream>
#include <ncurses.h>

Teacher::Teacher(const string& name, int id, const string& email, const string& password) : Person(name, id, email, password) {}

Teacher::Teacher(const char* name, int id, const string& email, const string& password) {

    this -> setName(name);
    this -> setId(id);
    this -> setEmail(email);
    this -> setPassword(password);
}   


void Teacher::showInformation() const {
    cout << "Teacher: " << *this << endl;
    
}

void Teacher::assignGrade(Student& student, const Grade& grade) {
    student.addGrade(grade);
    ofstream file("grades_" + to_string(student.getId()) + ".dat", ios::binary | ios::app);
    file.write(reinterpret_cast<const char*>(&grade), sizeof(grade)); 
    file.close();
}

ostream& operator<<(ostream& os, const Teacher& teacher) {
    os << teacher.getName() << " " << teacher.getId();
    return os;
}

istream& operator>>(istream& is, Teacher& teacher) {
    string name;
    int id;
    is >> name >> id;
    teacher.setName(name);
    teacher.setId(id);
    return is;
}