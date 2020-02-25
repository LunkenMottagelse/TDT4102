#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class Blackjack{
private:
    vector<Card> hand;

public:
    Blackjack();
    void addCard(Card newCard);
    void clearHand();
    int blackjackVal();
    void showDealer();
    void printHand();
};

void playBlackjack();