#include "std_lib_facilities.h"
#include "temps.h"
#include "Graph.h"
#include "Simple_window.h"

istream& operator>>(istream& is, Temps& t){
    string sMax {""};
    string sMin {""};

    is >> sMax >> sMin;
    t.max = stod(sMax);
    t.min = stod(sMin);
    return is;
}

vector<Temps> tempsAsVec(string fileName){
    vector<Temps> allTemps;

    ifstream ist {fileName};
    if (!ist) throw invalid_argument("File does not exist!");

    while (!ist.eof()){
        Temps tempTemp;
        ist >> tempTemp;
        allTemps.push_back(tempTemp);
    }
    return allTemps;
}

void graphicalRepresentation(){
    constexpr int xMax {1300};
    constexpr int yMax {700};
    constexpr int xOffset {100};
    constexpr int yOffset {60};
    constexpr int xSpace {60};
    constexpr int ySpace {60};

    constexpr int xLength {xMax - xOffset - xSpace};
    constexpr int yLength {yMax - yOffset - ySpace};

    constexpr int firstDay {0};
    constexpr int lastDay {365};
    constexpr int maxYVal {30};
    constexpr int minYVal {-30};

    constexpr double xScale {static_cast<double>(xLength)/(lastDay - firstDay)};
    constexpr double yScale {static_cast<double>(yLength)/(maxYVal - minYVal)};

    Scale xs {xOffset, firstDay, xScale};
    Scale ys {yMax - yOffset, minYVal, -yScale};

    Window win {Point {100, 100}, xMax, yMax, "Maks- og minimumstemperaturer i ett år."};

    Axis x {Axis::x, Point{xOffset, yMax  - ys(0)}, xLength, 12, "Feb                     Mar                     Apr                     Mai                     Jun                     Jul                     Aug                     Sep                     Okt                     Nov                     Des                     Jan"};
    x.label.move(-300, 0);

    Axis y {Axis::y, Point{xOffset, yMax - yOffset}, yLength, 6, "Degrees"};

    Open_polyline minTemp;
    Open_polyline maxTemp;

    vector<Temps> tempVals {tempsAsVec("temperatures.txt")};

    for (int i{0}; i < tempVals.size(); ++i){
        const int x {xs(i)};
        minTemp.add(Point{x, ys(tempVals[i].getMin())});
        maxTemp.add(Point{x, ys(tempVals[i].getMax())});
    }

    Text maxLabel {Point{60, maxTemp.point(0).y}, "Max"};
    Text minLabel {Point{60, minTemp.point(0).y}, "Min"};

    Text numOne {Point{80, ySpace + yLength / 6}, "20"};
    Text numTwo {Point{80, ySpace + 2 * yLength / 6}, "10"};
    Text numThr {Point{80, ySpace + 3 * yLength / 6}, "0"};
    Text numFou {Point{80, ySpace + 4 * yLength / 6}, "-10"};
    Text numFiv {Point{80, ySpace + 5 * yLength / 6}, "-20"};

    numOne.set_color(Color::black);
    numTwo.set_color(Color::black);
    numThr.set_color(Color::black);
    numFou.set_color(Color::black);
    numFiv.set_color(Color::black);


    maxLabel.set_color(Color::red);
    maxTemp.set_color(Color::red);
    minLabel.set_color(Color::blue);
    minTemp.set_color(Color::blue);
    x.set_color(Color::black);
    y.set_color(Color::black);

    win.attach(minTemp);
    win.attach(maxTemp);
    win.attach(minLabel);
    win.attach(maxLabel);
    win.attach(x);
    win.attach(y);
    win.attach(numOne);
    win.attach(numTwo);
    win.attach(numThr);
    win.attach(numFou);
    win.attach(numFiv);

    gui_main();
}

double Temps::getMax(){
    return max; 
}

double Temps::getMin(){
    return min;
}