#include "animal.h"
#include "std_lib_facilities.h"
#include "Graph.h"

string Animal::toString(){
    string printstring {"Animal: " + name + ", " + to_string(age)};
    return printstring;
}

string Dog::toString(){
    string printstring {"Dog: " + name + ", " + to_string(age)};
    return printstring;
}

string Cat::toString(){
    string printstring {"Cat: " + name + ", " + to_string(age)};
    return printstring;
}

void testAnimal(){
    using namespace Graph_lib;
    Cat katt {"Pusur", 5};
    //Animal dyr {"Oliver", 35};
    Dog hund {"Bolivar", 89};

    //cout << katt.toString() << endl << hund.toString() << endl << dyr.toString() << endl << endl << endl;

    Vector_ref<Animal> test {};
    //test.push_back(dyr);
    test.push_back(katt);
    test.push_back(hund);
    for (int i {0}; i < test.size(); ++i){
        cout << test[i].toString() << endl;
    }

    return;
}