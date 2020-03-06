#pragma once
#include "std_lib_facilities.h"

class Car{
private:
    int freeSeats;

public:
    Car(int free): freeSeats{free} {}
    bool hasFreeSeats() const;
    void reserveFreeSeat();
};

