#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes (int startValue,int increment,int numTimes);

void incrementByValueNumTimesRef (int& startValue, int increment, int numTimes);

void swapNumbers(int& a, int& b);

void randomizeVector(vector<int>& vec, int n);

void sortVector(vector<int>& vec);

double medianOfVector (const vector<int>& vec);

struct Student{
    string name;
    string studyProgram;
    int age;
    Student(string n, string sP, int a);
};

void printStudent(const Student& stud);

string randomizeString(int strLen, char upper, char lower);

string readInputToString(char upper, char lower, int strLen);

int countChar(string line, char test);

