#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

void testCallByValue(){
    int v0 {5};
    int increment {2};
    int iterations {10};
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference(){
    int v0 {5};
    int preVal {v0};
    int increment {2};
    int iterations {10};
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << preVal << " increment: " << increment << " iterations: " << iterations << " result: " << v0 << endl;
}

void testVectorSorting(){
    vector<int> percentages (0);
    int n {10};
    randomizeVector(percentages, n);

    cout << "Foer bytte:\n";
    for (int i {0}; i < n; ++i){
        cout << "Verdi " << i + 1 << ":\t" << percentages[i] << endl;
    }
    swapNumbers(percentages[0], percentages[1]);

    cout << "Etter bytte:\n";
    for (int i {0}; i < n; ++i){
        cout << "Verdi " << i + 1 << ":\t" << percentages[i] << endl;
    }

    sortVector(percentages);

    cout << "Etter sortering:\n";
    for (int i {0}; i < n; ++i){
        cout << "Verdi " << i + 1 << ":\t" << percentages[i] << endl;
    }

    double median = medianOfVector(percentages);
    cout << "Median:\t" << median << endl;
}

void testStruct(){
    Student torstein {"Torstein Holmengen", "ELSYS", 19};
    printStudent(torstein);
}

void testMenu(){
    bool keepon {true};
    while (keepon){
        cout << "Velg ett av alternativene:\n1) Kjoer testCallByValue\n2) Kjoer testCallByReference\n3) Kjoer testVectorSorting\n4) Kjoer testStruct\n5) Kjoer testString\n6) Spill Mastermind\n7) Avslutt\n";
        int select {0};
        cin >> select;
        cout << endl << endl; 
        switch (select){
        case 1:
            testCallByValue();
            break;
    
        case 2:
            testCallByReference();
            break;

        case 3:
            testVectorSorting();
            break;

        case 4:
            testStruct();
            break;

        case 5:
            testString();
            break;

        case 6:
            playMastermind();
            break;

        case 7:
            keepon = false;
            break;



        default:
            break;
        }
    }

}

void testString(){
    string grades {""};
    constexpr char lowestValChar {'A'};
    constexpr char highestValChar {'F'};
    constexpr int gradesNumber {8};
    grades = randomizeString(gradesNumber, highestValChar, lowestValChar);

    cout << "Grades:\t" << grades << endl << endl;

    vector<int> gradeCount (0);

    for (char i : "FEDCBA"){
        gradeCount.push_back(countChar(grades, i));
    }

    int gradeSum {0};
    for (int i {0}; i < gradeCount.size(); ++i){
        gradeSum += i * gradeCount[i];
    }
    double average {static_cast<double>(gradeSum) / gradesNumber};
    cout << "Gjennomsnitt:\t" << average << endl;

    /*string inGrades;
    inGrades = readInputToString(highestValChar, lowestValChar, gradesNumber);

    cout << "Grades:\t" << inGrades << endl;*/

    return;
}