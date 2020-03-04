#include "std_lib_facilities.h"
#include "Car.h"

bool Car::hasFreeSeats() const{
    bool free {false};

    if (freeSeats > 0) free = true;
    return free;
}

void Car::reserveFreeSeat(){
    --freeSeats;
    return;
}