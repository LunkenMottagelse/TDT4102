#pragma once


class Dummy{
public:
    int* num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy& dum) {
        num = new int{*dum.num};
    }
    Dummy& operator=(const Dummy& dum){
        delete num;
        num = new int{*dum.num};
        return *this;
    }
    
    ~Dummy() {
        delete num;
    }
};

void dummyTest();