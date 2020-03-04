#include "Car.h"
#include "Person.h"
#include "std_lib_facilities.h"

void Person::setEmail(string mail){
    email= mail;
    return;
}

string Person::getEmail() const{
    return email;
}

string Person::getName() const{
    return name;
}

bool Person::hasAvailableSeats() const{
    bool result;
    if (car != nullptr){
        result = car->hasFreeSeats();
    }
    else result = false;
    return result;
}
