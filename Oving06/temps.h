#pragma once
#include "std_lib_facilities.h"

class Temps{
private:
    double max;
    double min;
public:
    friend istream& operator>>(istream& is, Temps& t);
    double getMin();
    double getMax();
};

vector<Temps> tempsAsVec(string fileName);

void graphicalRepresentation();

class Scale{
private:
    int coordBase;
    int valBase;
    double scale;

public:
    Scale(int b, int vb, double s):coordBase {b}, valBase{vb}, scale{s} {}
    int operator()(int v) const { return coordBase + (v - valBase) * scale;}
};