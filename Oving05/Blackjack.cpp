#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

Blackjack::Blackjack() {};

void Blackjack::addCard(Card newCard){
    hand.push_back(newCard);
    return;
}

void Blackjack::clearHand(){
    hand.clear();
    return;
}
    
int Blackjack::blackjackVal(){
    int sumCardVal {0}; int aceCount {0}; int intCardVal {0};
    Rank cardVal;
    for (int i {0}; i < hand.size(); ++i){
        cardVal = hand[i].getRank();
        if (cardVal == Rank::ace){
            ++aceCount;
        }
        else{
            intCardVal = static_cast<int>(cardVal);
            if (intCardVal > 10) sumCardVal += 10;
            else sumCardVal += intCardVal;
        }
    }

    if (aceCount > 1){
        sumCardVal += (aceCount - 1);
        if (sumCardVal <= 10) sumCardVal += 11;
        else sumCardVal += 1;
    }
    else if (aceCount == 1){
        if (sumCardVal <= 10) sumCardVal += 11;
        else sumCardVal += 1;
    }

    return sumCardVal;
}

void Blackjack::showDealer(){
    cout << hand[0].toString() << endl;
    return;
}

void Blackjack::printHand(){
    string card;
    for (int i {0}; i < hand.size(); ++i){
        card = hand[i].toString();
        cout << card << ", ";
    }
    cout << endl;
    return;
}





void playBlackjack(){
    // Game setup
    Blackjack dealer {};
    Blackjack player {};
    CardDeck playingDeck {};
    playingDeck.shuffle();

    for (int i {0}; i < 2; ++i){
        player.addCard(playingDeck.drawCard());
        dealer.addCard(playingDeck.drawCard());
    }
    cout << "Dealer is showing ";
    dealer.showDealer();

    cout << "You are holding ";
    player.printHand();
    cout << "With a current value of " << player.blackjackVal() << ".\n";

    // Game loop
    bool quit {false};
    bool dealerDraw {true}; bool playerDraw {true};
    while (!quit){
        char in;
        cout << "Do you want to draw another card? (Y/N)\n";
        cin >> in;

        switch (in){
        case 'Y':
            player.addCard(playingDeck.drawCard());
            cout << "Your new hand is ";
            player.printHand();
            cout << "This gives a value of " << player.blackjackVal() << ".\n";

            if (dealer.blackjackVal() < 17){
                cout << "The dealer drew a card.\n";
                dealer.addCard(playingDeck.drawCard());
            }
            else{
                cout << "The dealer has stopped drawing.\n";
                dealerDraw = false;
            }
            break;
        
        case 'N':
            if (dealer.blackjackVal() < 17){
                cout << "The dealer drew a card.\n";
                dealer.addCard(playingDeck.drawCard());
            }
            else{
                cout << "The dealer has stopped drawing.\n";
                dealerDraw = false;
            }
            playerDraw = false;
            break;

        default:
            cout << "I did not understand this, please try again.\n";
            break;
        }

        if (player.blackjackVal() >= 21 || dealer.blackjackVal() > 21){
            quit = true;
        }
        if (!playerDraw && !dealerDraw){
            quit = true;
        }
    }

    // Aftermath
    if (dealer.blackjackVal() > 21 && player.blackjackVal() <= 21){
        cout << "Congratulations, you win!\n";
    }
    else if (player.blackjackVal() > 21){
        cout << "Sorry, you lose!\n";
    }
    else if (player.blackjackVal() == 21){
        cout << "Congratulations, you win!\n";
    }
    else if (player.blackjackVal() > dealer.blackjackVal()){
        cout << "Congratulations, you win!\n";
    }
    else {
        cout << "Sorry, you lose!\n";
    }

    // Cleaning of variables:

    player.clearHand();
    dealer.clearHand();

    return;
}