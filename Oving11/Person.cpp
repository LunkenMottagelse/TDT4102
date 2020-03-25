#include "Person.h"
#include <iostream>
#include <list>
using namespace std;

void Person::setFirstName(string first){
    firstName = first;
    return;
}

void Person::setLastName(string last){
    lastName = last;
    return;
}

void Person::setFullName(string first, string last){
    setLastName(last);
    setFirstName(first);
    return;
}

string Person::getFullName() const{
    string s {firstName + " " + lastName};
    return s;
}

string Person::getFirstName() const{
    return firstName;
}

string Person::getLastName() const{
    return lastName;
}

void Person::printPerson() const{
    cout << firstName << " " << lastName;
}

ostream& operator<<(ostream& os, Person p){
    os << p.firstName << " " << p.lastName;
    return os;
}

void insertOrdered(list<Person>& lst, const Person& p){
    for (auto it = lst.begin(); it != lst.end(); ++it){
        if (it->getFullName() > p.getFullName()){
            lst.insert(it, p);
            break;
        }
    }
    return;
}