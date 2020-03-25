#pragma once
#include <random>
#include <vector>

template<typename T>
T maximum(T val1, T val2){
    if (val1 > val2) return val1;
    else return val2;
}

template<typename T>
void shuffle(std::vector<T>& vec){
    T temp;
    int changeVal1;
    int changeVal2;
    for (int i {0}; i < 1000; ++i){
        changeVal1 = rand() % vec.size();
        changeVal2 = rand() % vec.size();

        temp = vec[changeVal1];
        vec[changeVal1] = vec[changeVal2];
        vec[changeVal2] = temp;
    }
    return;
}