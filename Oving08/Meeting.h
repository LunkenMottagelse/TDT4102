#pragma once
#include "std_lib_facilities.h"
#include "Person.h"
#include "Car.h"

enum class Campus {Trondheim, Aalesund, Gjoevik};

ostream& operator<<(ostream& os, const Campus& c);

class Meeting{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static set<const Meeting*> meetings;

public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    const Person* getLeader() const;
    void addParticipant(const Person* person);
    vector<string> getParticipantList() const;
    vector<const Person*> findPotentialCoDriving() const;

    Meeting(int d, int startt, int endt, Campus loc, string sub, const Person* lead) : day{d}, startTime{startt}, endTime{endt}, location{loc}, subject{sub}, leader{lead}{
        this->addParticipant(leader);
        meetings.insert(this);
    }
    ~Meeting(){
        meetings.erase(this);
    }
};

ostream& operator<<(ostream& os, const Meeting& m);