#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person{
private:
    string name;
    string email;
    Car* car;

public:
    Person(string n, string e, Car* c = nullptr) : name{n}, email{e}, car{c}{}
    string getEmail() const;
    string getName() const;
    void setEmail(string mail);
    bool hasAvailableSeats() const;
    friend ostream& operator<<(ostream& os, const Person& p){
        os << p.name << ", " << p.email << ", ";
        if (p.hasAvailableSeats()) os << "Seats avaliable.";
        else os << "No seats avaliable.";

        return os;
    }
};
// Det er ikke meningen � endre p� Person-objektet og dermed er det lurt � v�re p� den sikre siden. En burde bruke const s� mye det lar seg gj�re, men n�r det er meningen at man skal
// endre p� noe kan man ikke ha en const.