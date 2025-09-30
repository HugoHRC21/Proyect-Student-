#include <UserManager.h> 
#include <fstream>
#include <iostream>
#include <ncurses.h> 

using namespace std;

bool UserManager::validateUser (const string& email, const string& password){
    for(const auto& student:students){
        if(student.getEmail() == email && student.getpassword() == password){
            return true;    
        }
    }
    for(const auto& teacher:teachers){
        if(teacher.getEmail() == email && teacher.getpassword() == password){
            return true;
        }
    }
    return false;
}


void UserManager::showUserInfo(const string& email){
    for(const auto& student:students){
        if(student.getemail() == email){
            printw("Student Info: \n");
            printw("Name: ", student.getName() ", ID: ", student.getId());
            return;
        }
    }

    for(const auto& teacher:teachers){
        if(teacher.getEmail() == email){
            printw("Teacher Info: \n");
            printw("Name: ", teacher.getname(), ", ID: ", teacher.getId());
            return;
        }
    }
    printw("User not found.");
}


UserManager::UserManager(int hashSize) : userTable(hashSize) {
}


int UserManager::hashFunction(const string& email) {
    int hash = 0;
    for (char ch : email) {
        hash += ch; 
    }
    return hash % userTable.size(); 
}

bool UserManager::insert(string email){
    int index = hashFunction(email);

    while(!userTable[index].empty()){
        if(userTable[index].front == email){
            return false;
        }
    index = (index + 1) % userTable.size();
    }

    userTable[index].push_back(email);
    return false;
}

void UserManager::LoadFromFile(const string& filename){
    ifstream file(filename);
    if(!file){
        printw ("Error al abrir el archivo. %s\n", filename.c_str());
        return;
    }
    string email;
    while(getline(file, email)){
        insert(email);
    }
    file.close();
}
