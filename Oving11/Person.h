#pragma once
#include <iostream>
#include <list>
using namespace std;

class Person{
    string firstName;
    string lastName;
public:
    Person(string first, string last) : firstName{first}, lastName{last} {}
    void setFirstName(string first);
    void setLastName(string last);
    void setFullName(string first, string last);
    string getFullName() const;
    string getFirstName() const;
    string getLastName() const;
    void printPerson() const;

    friend ostream& operator<<(ostream& os, Person p);
};

void insertOrdered(list<Person>& lst, const Person& p);