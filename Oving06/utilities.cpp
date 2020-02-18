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

    if (!ost || !ist) error("Some of the filenames are not accessible.");
    int i {1};

    while (!ist.eof()){
        getline(ist, intermedium);
        if (ist.fail()) error("Bad data in data.");
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
        if (inst.fail()) continue;

        for (char a : testString){
            if (isalpha(a)){
                ++charCount[static_cast<int>(a) - static_cast<int>('a')];
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