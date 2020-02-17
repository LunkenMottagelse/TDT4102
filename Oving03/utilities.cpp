#include "std_lib_facilities.h"
#include "cannonball.h"

int randomWithLimits(int upper, int lower){
    if (upper < 0 || lower < 0 || lower >= upper) throw invalid_argument("Numbers in randomWithLimits are invalid!");
    int randomNum {rand()};
    randomNum = (randomNum % (upper - lower + 1)) + lower;
    return randomNum;
}

void playTargetPractice(){
    const int targetDistance {randomWithLimits(1000, 100)};
    bool conclusion {false};
    unsigned int attempt{1};
    cout << "Du skal treffe en blink med kanonen din" << targetDistance << "meter unna. ";
    cout << "Du får 10 forsøk på å treffe innen 5 meter av blinken, og du skal sikte med vinkel og fart på kanonkulen.\n";
    while (!conclusion){
        cout << "Forsøk nr. " << attempt << endl;
        double angle { degToRad( getUserInputTheta() ) };
        double speed { getUserInputAbsVelocity() };
        double distanceFromTarget { targetPractice(targetDistance, getVelocityX(angle, speed),  getVelocityY(angle, speed)) };
        ++attempt;
        if (distanceFromTarget <= 5 && distanceFromTarget >= -5){
            --attempt;
            conclusion = true;
            cout << "Gratulerer, du traff blinken!\n";
        }
        else if (distanceFromTarget < 0){
            cout << "Bom! Kulen landet " << -distanceFromTarget << " meter foran blinken.\n";
        }
        else {
            cout << "Bom! Kulen landet " << distanceFromTarget << "meter bak blinken.\n";
        }
        printTime( flightTime( getVelocityY(angle, speed)));
        if (attempt > 10){
            conclusion = true;
            cout << "Du har ikke flere forsøk! Bedre lykke neste gang.";
        }
    }
    return;
}