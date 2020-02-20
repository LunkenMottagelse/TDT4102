#include "std_lib_facilities.h"
#include "utilities.h"

void writeToFile(string file){
    ofstream ost {file};
    bool quit {false};
    string in;
    while (!quit){
        cin >> in;
        if (in == "quit"){
            quit = true;
            break;
        }
        ost << in << endl;
    }
}

void addLineNum(string inFile, string outFile){
    ofstream ost {outFile};
    ifstream ist {inFile};
    string intermedium {""};

    if (!ost || !ist) throw invalid_argument("Some of the filenames are not accessible.");
    int i {1};

    while (!ist.eof()){
        getline(ist, intermedium);
        if (ist.fail()) throw invalid_argument("Bad data in data.");
        intermedium = to_string(i) + " " + intermedium;
        ost << intermedium << endl;
        ++i;
    }
    return;
}

void charStat(string inFile){
    vector<int> charCount (26);
    ifstream inst {inFile};
    string testString {""};

    if (!inst) throw invalid_argument("Filename does not exist.");

    while (!inst.eof()){
        getline(inst, testString);
        if (inst.fail()) throw invalid_argument("Wrong input.");

        for (int i {0}; i < testString.size(); ++i){
            if (testString[i] == '§'){
                continue;
            }
            else if (testString[i] == 'æ' || tolower(testString[i]) == 'ø' || tolower(testString[i]) == 'å' || testString[i] == 'Æ' || tolower(testString[i]) == 'Ø' || tolower(testString[i]) == 'Å'){
                continue;
            }
            
            if (isalpha(testString[i])){
                ++charCount[static_cast<int>(tolower(testString[i])) - static_cast<int>('a')];
            }
        }

    }
    char c;
    for (int j {0}; j < 26; ++j){
        c = static_cast<char>(static_cast<int>('a') + j);
        cout << c << ": " << charCount[j] << endl;
    }
    return;
}
CourseCatalog::CourseCatalog() {};

// Insert skriver ikke over en allerede eksisterende verdi, det gjør klammeparanteser.
void CourseCatalog::addCourse(string code, string name){
    courses.insert(pair<string, string>(code, name));
    return;
}

void CourseCatalog::removeCourse(string code){
    courses.erase(code);
    return;
}

string CourseCatalog::getCourse(string code){
    return courses[code];
}

ostream& operator<<(ostream& os, const CourseCatalog& cc){
    string ostring {""};
    for (auto i : cc.courses){
        ostring += i.first + ", \"" + i.second + "\" \n";
    }
    return os << ostring;
}

ofstream& operator<<(ofstream& ofs, const map<string, string>& mp){ // Uheldig metode, men siden dette er et lite prosjekt går det bra.
    string ostring {""};
    for (auto i : mp){
        ostring += i.first + ", \"" + i.second + "\" \n";
    }
    ofs << ostring;
    return ofs;
}

void CourseCatalog::loadData(string fileName){
    ifstream ist {fileName};
    string singleLoad {""};

    if (!ist) throw invalid_argument("Filename does not exist.");

    while (!ist.eof()){
        getline(ist, singleLoad);
        if (ist.fail()) continue;

        int comma {0};

        for (int i{0}; i < singleLoad.size(); ++i){
            if (singleLoad[i] == ','){
                comma = i;
                break;
            }
        }
        string code {singleLoad.substr(0, comma)};
        string name {singleLoad.substr(comma + 3, singleLoad.size() - comma - 5)};

        addCourse(code, name);
    }
    return;
}
    
void CourseCatalog::writeData(string fileName){
    ofstream ost {fileName};
    if (!ost) throw invalid_argument("Filename does not exist.");

    ost << courses;
    return;
}