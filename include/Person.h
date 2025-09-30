#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    int id;
    string email;
    string password;

public:
    Person();
    Person(string name, int id, string email, string password);
    virtual void showInformation() const = 0; 

    void setName(string name);
    void setId (int id);  
    void setEmail (string email);
    void setPassword (string password);  

    string getName() const;
    int getId() const;
    string getEmail();
    string getPassword();
};

#endif 