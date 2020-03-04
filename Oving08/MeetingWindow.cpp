#include "std_lib_facilities.h"
#include "MeetingWindow.h"
#include "Person.h"
#include "GUI.h"

void MeetingWindow::addPerson(){
    people.push_back(new Person {personName.get_string(), personEmail.get_string()});
    return;
}

void MeetingWindow::printPerson(){
    for (Person* p : people){
        cout << p->getName() << ", " << p->getEmail() << endl;
    }
    return;
}