#include "std_lib_facilities.h"
#include "utilities.h"



Student::Student(string n, string sP, int a) : name {n}, studyProgram {sP}, age {a}{

}

int incrementByValueNumTimes (int startValue,int increment,int numTimes){
    for(int i {0}; i < numTimes; ++i) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef (int& startValue, int increment, int numTimes){
    for(int i {0}; i < numTimes; ++i) {
        startValue += increment;
    }
    return;
}

void swapNumbers(int& a, int& b){
    int tempVal {b};
    b = a;
    a = tempVal;
    return;
}

void randomizeVector(vector<int>& vec, int n){
    for (int i {0}; i < n; ++i){
        vec.push_back( rand() % 101 );
    }
    return;
}

void sortVector(vector<int>& vec){
    int i {1};
    while (i < vec.size()){
        int j {i};
        while (j > 0 && vec[j-1] > vec[j]){
            swapNumbers(vec[j], vec[j-1]);
            --j;
        }
        ++i;
    }
}

double medianOfVector (const vector<int>& vec){
    double returnValue {0};
    if (vec.size() % 2 == 0){
        returnValue = ( vec[vec.size() / 2] + vec[(vec.size() / 2.0) - 1] ) / 2.0;
    }
    else{
        returnValue = vec[vec.size() / 2]; // Bruker integre med vilje for å runde tallet ned.
    }
    return returnValue;
}

void printStudent(const Student& stud){
    cout << "Navn: " << stud.name << ", Alder: " << stud.age << ", Studieretning: " << stud.studyProgram << endl;
    return;
}

string randomizeString(int strLen, char upper, char lower){
    string randString {""};
    int upperNum {static_cast<int>(upper)};
    int lowerNum {static_cast<int>(lower)};

    for (int i {0}; i < strLen; ++i){
        randString += static_cast<char>(rand() % (upperNum - lowerNum + 1) + lowerNum);
    }
    return randString;
}

string readInputToString(char upper, char lower, int strLen){
    cout << "Skriv inn " << strLen << " bokstaver mellom " << lower << " og " << upper << endl;

    upper = toupper(upper);
    lower = toupper(lower);

    int upperNum {static_cast<int>(upper)};
    int lowerNum {static_cast<int>(lower)};
    string inData;
    bool wrongData {true};

    while (wrongData){
        cin >> inData;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Input var rart, proev igjen!\n";
        }
        else if (inData.size() != strLen){
            cin.ignore();
            cout << "Feil mengde bokstaver, proev igjen!\n";
        }
        else{
            for (char i : inData){
                if (!isalpha(i)){
                    cout << "Input besto ikke bare av bokstaver, proev igjen!\n";
                    wrongData = true;
                    break;
                }
                i = toupper(i);
                int iNum {static_cast<int>(i)};
                if ( !(iNum <= upperNum && iNum >= lowerNum) ){
                    cout << "Bokstavene er ikke innenfor rekkevidde, proev igjen!\n";
                    wrongData = true;
                    break;
                }
                wrongData = false;
            }
        }
    } 

    for (int i {0}; i < strLen; ++i){
        inData[i] = toupper(inData[i]);
    }
    return inData;
}

int countChar(string line, char test){
    int times {0};
    for (int i {0}; i < line.size(); ++i){
        if (line[i] == test){
            ++times;
        }
    }
    return times;
}