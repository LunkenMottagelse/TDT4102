#pragma once
#include "std_lib_facilities.h"
#include "GUI.h"
#include "Person.h"
using namespace Graph_lib;


class MeetingWindow : public Window{
private:
    static constexpr int pad {50};
    static constexpr int btnW {100};
    static constexpr int btnH {70};
    static constexpr int fieldW {400};
    static constexpr int fieldH {40};
    static constexpr int fieldPad {100};
    const int winH {y_max()};
    const int winW {x_max()};

    Vector_ref<Person> people;
    In_box personName;
    In_box personEmail;
    Button quitBtn;
    Button personNewBtn;


public:
    MeetingWindow(Point xy, int w, int h, const string& title) : Window{xy, w, h, title}, quitBtn{Point{winW - pad - btnW, pad}, btnW, btnH, "Avslutt", cb_quit},
            personName{Point{fieldPad, pad}, fieldW, fieldH, "Navn"}, personEmail{Point{fieldPad, 2*pad + fieldH}, fieldW, fieldH, "E-post"}, 
            personNewBtn{Point{fieldPad, 3*pad + 2*fieldH}, btnW, btnH, "Legg til person", cb_new_person} {
        attach(quitBtn);
        attach(personName);
        attach(personEmail);
        attach(personNewBtn);
    }

    void addPerson();
    void printPerson();

    static void cb_quit(Address, Address pw){
        reference_to<MeetingWindow>(pw).hide();
    }

    static void cb_new_person(Address, Address pw){
        reference_to<MeetingWindow>(pw).addPerson();
    }
};