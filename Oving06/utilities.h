#pragma once
#include "std_lib_facilities.h"

void writeToFile(string file);

void addLineNum(string inFile, string outFile);

void charStat(string inFile);

class CourseCatalog{
private:
    map<string, string> courses;
    
public:
    CourseCatalog();
    void addCourse(string code, string name);
    void removeCourse(string code);
    string getCourse(string code);
    friend ostream& operator<<(ostream& os, const CourseCatalog& cc);
    friend ofstream& operator<<(ofstream& os, const map<string, string>& mp);
    void loadData(string fileName);
    void writeData(string fileName);
};