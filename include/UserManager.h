#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <Teacher.h>
#include <Student.h>
#include <FileHaldling>

class UserManager{
    private:
    vector<Teacher> teachers;
    vector<Student> students;
}

bool validateUser(string email, string password);
void showUserInfo(string emai);
void loadFromFile(const string& filename);
void insert(const string& email);
int hashFunction(const string& email);

#endif