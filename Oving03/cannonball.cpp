#include "cannonball.h"
#include "std_lib_facilities.h"

double acclY(){
    double acceleration{ -9.81 };
    return acceleration;
}

double velY(double initVelocityY, double time){
    double speed { initVelocityY + acclY() * time };
    return speed;
}

double posX(double initPositionX, double initVelocityX, double time){
    double position { initPositionX + initVelocityX * time };
    return position;
}

double posY(double initPositionY, double initVelocityY, double time){
    double position { initPositionY + initVelocityY * time + (acclY() / 2) * time * time };
    return position;
}

void printTime(double time){
    int roundTime {static_cast<int>(time)}; // Runder av antall sekunder nedover.

    int hours { roundTime / (60 * 60) };
    int minutes { ( roundTime % (60*60) ) / 60 };
    int seconds { roundTime % 60 };
    cout << "Tid:   Timer: " << hours << ", Minutter: " << minutes << ", Sekunder: " << seconds << endl;
    return;
}

double flightTime(double initVelocityY){
    double timeInAir { -2 * initVelocityY / acclY() };
    return timeInAir;
}

double getUserInputTheta(){
    cout << "Oppgi en vinkel i grader for kannonen:\n";
    double deg {-1};
    cin >> deg;
    if (cin.fail() || deg < 0 || deg > 90) throw invalid_argument("Feil input i vinkelfunksjonen!");

    return deg;
}

double getUserInputAbsVelocity(){
    cout << "Oppgi utskytningshastigheten fra kannonen:\n";
    double speed {-1};
    cin >> speed;
    if ( cin.fail() || speed < 0 ) throw invalid_argument("Feil input i hastighetsfunksjonen!");

    return speed;
}

double degToRad(double deg){
    constexpr double pi {3.14159265358979323846};
    double rad {deg / 180 * pi};
    return rad;
}

double getVelocityX(double theta, double absVelocity){
    double speed { absVelocity * cos(theta) };
    return speed;
}

double getVelocityY(double theta, double absVelocity){
    double speed { absVelocity * sin(theta) };
    return speed;
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> speedVec(2);
    speedVec[0] = getVelocityX(theta, absVelocity);
    speedVec[1] = getVelocityY(theta, absVelocity);
    return speedVec;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double timeInAir {flightTime(velocityY)};
    double finalX { posX(0, velocityX, timeInAir) };
    return finalX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double actualDistance {getDistanceTraveled(velocityX, velocityY)};
    double errorDist {actualDistance-distanceToTarget};
    return errorDist; 
}