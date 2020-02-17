#include "mastermind.h"
#include "utilities.h"
#include "tests.h"
#include "std_lib_facilities.h"
#include "masterVisual.h"

void playMastermind(){
    constexpr int codeSize {4};
    constexpr int letters {6};
    constexpr int numTry {6};
    int intSolved {0};
    int corrChar {0};

    string code;
    string guess;
    bool solved {false};

    char minLetter {'A'};
    char maxLetter {static_cast<char>(static_cast<int>('A') + letters - 1)};
    code = randomizeString(codeSize, maxLetter, minLetter);

    MastermindWindow mwin{Point{71,0}, winH, winW, "Mastermind"};
    addGuess(mwin, code, codeSize, 'A', 0);
    hideCode(mwin, codeSize);
    //cout << code << endl << endl;  // Testing.

    int counter {1};
    while (!solved){
        guess = mwin.getInput(codeSize, minLetter, maxLetter);
        intSolved = checkCharactersAndPosition(code, guess);
        corrChar = checkCharacters(code, guess, minLetter, maxLetter);

        addGuess(mwin, guess, codeSize, minLetter, counter);
        addFeedback(mwin, intSolved, corrChar, codeSize, counter);

        if (intSolved == codeSize){ 
            solved = true;
            cout << "Gratulerer, du klarte det!\n";
            break;
        }


        cout << "Antall riktige:\t" << intSolved << "\nAntall av riktig type:\t" << corrChar << endl << endl;
        ++counter;
        if (counter > numTry){
            cout << "Du har brukt alle forsøkene dine, riktig kode var " << code << endl;
            break;
        }
    }
    mwin.redraw();
    return;

}

int checkCharactersAndPosition(string code, string guess){
    int correct {0};
    for (unsigned int i {0}; i < code.size(); ++i){
        if (code[i] == guess[i]){
            ++correct;
        }
    }
    return correct;
}

int checkCharacters(string code, string guess, char min, char max){
    int correct {0};
    int a {0};
    int b {0};
    for (char i {min}; i <= max; ++i){
        a = countChar(code, i);
        b = countChar(guess, i);
        if (a > b) correct += b;
        else correct += a;
    }
    return correct;
}
