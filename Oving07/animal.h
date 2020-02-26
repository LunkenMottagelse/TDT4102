#pragma once
#include "std_lib_facilities.h"

class Animal{
protected:
    string name;
    int age;

public:
    Animal(string n, int a): name{n}, age{a} {}
    virtual string toString() = 0;
};

class Cat : public Animal{
public:
    using Animal::Animal;
    string toString();
};

class Dog : public Animal{
public:
    using Animal::Animal;
    string toString();
};

void testAnimal();