#include <Student.h>
#include <fstream>
#include <iostream>
#include <ncurses.h> 

Student::Student(string& name, int id, const string& email, const string& password) : Person(name, id, email, password) {}

Student::Student(const char* name, int id ) {
    this -> setName(name);
    this -> setId(id);
}

void Student::showInformation() const {
    printw("Student: %s\n", this->name.c_str());
    for (const auto& grade : grades) {
       printw("Subject: %s, Score: %.2f\n", grade.subject.c_str(), grade.score);
    }
}

void Student::addGrade(const Grade& grade) {
    grades.push_back(grade);
}

void Student::consultGrades() {
    ifstream file("grades_" + to_string(this->getId()) + ".dat", ios::binary);
    if(!file.is_open()){
        printw("Error al abrir el archivo de calificaciones.\n");
        return;
    }
    Grade grade("", 0);
    while (file.read(reinterpret_cast<char*>(&grade), sizeof(grade))) {
        printw("Subject: %s, Score: %.2f\n", grade.subject.c_str(), grade.score);
    }
    file.close();
}

vector<Grade> Student::getGrades()  {
    return this->grades; 
}

void Student::setGrade(const Grade grade) {
   
    if (grade.score < 0 || grade.score > 100) {
        printw("Error: Score must be between 0 and 100.\n");
        throw invalid_argument("Score must be between 0 and 100.");
    }
    grades.push_back(grade); 
}

ostream& operator<<(ostream& os, const Student& Student) {
    os << Student.getName() << " " << Student.getId();
    return os;
}

istream& operator>>(istream& is, Student& student) {
    string name;
    int id;
    is >> name >> id;
    student.setName(name);
    student.setId(id);
    return is;
}