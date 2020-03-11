#include "memoryHandling.h"
#include <iostream>

void fillInFibonacciNumbers(int result[], int length){
    if (length == 0) return;
    else if (length == 1){
        result[0] = 0;
    }
    else if (length == 2){
        result[0] = 0;
        result[1] = 1;
    } 
    else {
        result[0] = 0;
        result[1] = 1;
        for (int i {2}; i < length; ++i){
            result[i] = result[i - 1] + result[i - 2];
        }
    }
    return;
}

void printArray(int arr[], int length){
    for (int i{0}; i < length; ++i){
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
    return;
}

void createFibonacci(){
    std::cout << "Hvor mange tall i Fibonaccirekken skal genereres?\n";
    int length {0};
    std::cin >> length;

    int* fibbonacci {new int[length]};

    fillInFibonacciNumbers(fibbonacci, length);

    printArray(fibbonacci, length);

    delete[] fibbonacci;
    return;
}