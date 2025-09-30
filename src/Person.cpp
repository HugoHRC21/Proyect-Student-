#include <Person.h>

Person::Person() {
    this -> name = "";
    this -> id = -1;
    this -> email = "";
    this -> password = "";
}

Person::Person(string name, int id, string email, string password) : name(name), id(id), email(email), password(password) {}

void Person::setName(string name){
        this->name = name;
    }
void Person::setId (int id){
        this->id = id;
    }
void Person::setEmail(string Email){
    this->email = email;
}
void Person::setPassword(string password){
    this->password = password; 
}

string Person::getName() const {
        return this->name;
    }    
int Person::getId() const {
        return this->id;
    }
string Person::getEmail(){
    return this->email;
}
string Person::getPassword(){
    return this->password;
}
