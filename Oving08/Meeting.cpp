#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Person.h"

ostream& operator<<(ostream& os, const Campus& c){
    if (c == Campus::Trondheim){
        os << "Trondheim";
    }
    else if (c == Campus::Gjoevik){
        os << "Gjøvik";
    }
    else if (c== Campus::Aalesund){
        os << "Ålesund";
    }
    return os;
}

ostream& operator<<(ostream& os, const Meeting& m){
    os << m.getLocation() << " fra " << m.getStartTime() << " til " << m.getEndTime() << ". " << m.getSubject() << " med " << m.getLeader()->getName() << ".\nMøtedeltagere:\n";
    vector<string> par {m.getParticipantList()};
    for (string i : par){
        os << i << endl;
    }
    return os;
}

int Meeting::getDay() const{
    return day;
}

int Meeting::getStartTime() const{
    return startTime;
}

int Meeting::getEndTime() const{
    return endTime;
}

Campus Meeting::getLocation() const{
    return location;
}

string Meeting::getSubject() const{
    return subject;
}

const Person* Meeting::getLeader() const{
    return leader;
}

void Meeting::addParticipant(const Person* person){
    participants.insert(person);
    return;
}

set<const Meeting*> Meeting::meetings;

vector<string> Meeting::getParticipantList() const{
    vector<string> parLst {};
    for (const Person* i : participants){
        parLst.push_back(i->getName());
    }
    return parLst;
}

vector<const Person*> Meeting::findPotentialCoDriving() const{
    vector<const Person*> results;
    for (const Meeting* meet : meetings){
        if (meet != this){
            if (meet->getDay() == this->getDay() && meet->getLocation() == this->getLocation()){
                if (meet->getStartTime() - this->getStartTime() <= 1 && meet->getStartTime() - this->getStartTime() >= -1 && meet->getEndTime() - this->getEndTime() <= 1 && meet->getEndTime() - this->getEndTime() >= -1){
                    for (const Person* pers : meet->participants){
                        if (pers->hasAvailableSeats()){
                            results.push_back(pers);
                        }
                    }
                }
            }
        }
    }
    return results;
}