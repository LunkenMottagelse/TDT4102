#include "iteratorTest.h"
#include "Person.h"
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

void iteratorTest(){

/*    {
        vector<string> testVec {"Hei", "jeg", "heter", "Torstein"};

        for (vector<string>::iterator it = testVec.begin(); it != testVec.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;

        for (vector<string>::reverse_iterator it = testVec.rbegin(); it != testVec.rend(); ++it){
            cout << *it << " ";
        }
        cout << endl << endl;

        replace(testVec, "Torstein", "Replaced");
        for (vector<string>::iterator it = testVec.begin(); it != testVec.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
        




        set<string> testVec2 {"Hei", "jeg", "heter", "Torstein"};

        for (set<string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;

        for (set<string>::reverse_iterator it = testVec2.rbegin(); it != testVec2.rend(); ++it){
            cout << *it << " ";
        }
        cout << endl << endl;

        replaceSet(testVec2, "Torstein", "Replaced");
        for (set<string>::iterator it = testVec2.begin(); it != testVec2.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }*/


    Person pers1 {"Torstein", "Holmengen"};
    Person pers2 {"Bror", "Thorgersen"};
    Person pers3 {"Sylvester", "Stallone"};

    list<Person> lst;
    lst.push_back(pers2);
    lst.push_back(pers3);
    lst.push_back(pers1);

    Person testpers {"Egil", "Guttormsen"};

    insertOrdered(lst, testpers);

    Person testpers2 {"Aaron", "Black"};

    insertOrdered(lst, testpers2);

    for (auto it = lst.begin(); it != lst.end(); ++it){
        cout << *it << endl;
    }

    return;
}

void replace(vector<string>& vec, string old, string replacement){
    while (find(vec.begin(), vec.end(), old) != vec.end()){
        int i {0};
        for (auto it = vec.begin(); it != vec.end(); ++it){
            if (*it == old){
                vec.erase(it);
                break;
            }
            ++i;
        }
        vec.insert(vec.begin() + i, replacement);
    }
    return;
}

void replaceSet(set<string>& part, string old, string replacement){
    while (find(part.begin(), part.end(), old) != part.end()){
        int i {0};
        for (auto it = part.begin(); it != part.end(); ++it){
            if (*it == old){
                part.erase(it);
                break;
            }
            ++i;
        }
        part.insert(replacement);
    }
    return;
}

void replaceImp(vector<string>& vec, string old, string replacement){ // Dette er en langt bedre løsning da man 
    while (find(vec.begin(), vec.end(), old) != vec.end()){ // slipper å håndtere ugyldige iteratorer og ideen bak
        *find(vec.begin(), vec.end(), old) = replacement; // kommer tydeligere frem.
    }
    return;
}