#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck{
private:
    vector<Card> cards;
    void swap(int a, int b);
public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
};
