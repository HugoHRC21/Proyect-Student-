#include <FileHandling.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ncurses.h> 

using namespace std;

void saveTeacher(const Teacher& teacher) {
    ofstream file("teachers.dat", ios::binary | ios::app);
    if(!file){
    printw ("Error al abrir el arcihvo para guardar el profesor.\n");
    return;
    } 
    file << teacher;
    file.close();
}


void loadTeachers(vector<Teacher>& teachers) {
    ifstream file("teachers.dat", ios::binary);
    if(!file){
        printw ("Error al abrir el archivo para cargar profesores. \n");
        return;
    }   
    Teacher teacher("", 0, "","");
    while (file >> teacher) { 
        teachers.push_back(teacher);
    }
    file.close();
}


void saveStudent(const Student& student) {
    ofstream file("students.dat", ios::binary | ios::app);
    if(!file){
        printw ("error al abrir el archivo para guardar el estudiante. \n");
        return;
    }
    file << student; 
    file.close();
}

void loadStudents(vector<Student>& students) {
    ifstream file("students.dat", ios::binary);
    if(!file){
        printw ("error al abrir el archivo para cargar estudiantes. \n");
    }
    Student student("", 0);
    while (file >> student) { 
        students.push_back(student);
    }
    file.close();
}