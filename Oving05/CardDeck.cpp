#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

CardDeck::CardDeck(){
    vector<Suit> suits {Suit::clubs, Suit::diamonds, Suit::hearts, Suit::spades};
    vector<Rank> ranks {Rank::two, Rank::three, Rank::four, Rank::five, Rank::six, Rank::seven, Rank::eight, Rank::nine, Rank::ten, Rank::jack, Rank::queen, Rank::king, Rank::ace};

    for (int i {0}; i < 4; ++i){
        for (int j {0}; j < 13; ++j){
            cards.push_back(Card(suits[i], ranks[j]));
        }
    }
}

void CardDeck::swap(int a, int b){
    Card temp {cards[a]};
    cards[a] = cards[b];
    cards[b] = temp;
    return;
}

void CardDeck::print(){
    for (int i {0}; i < cards.size(); ++i){
        cout << cards[i].toString() << endl;
    }
}

void CardDeck::printShort(){
    for (int i {0}; i < cards.size(); ++i){
        cout << cards[i].toStringShort() << endl;
    }
}

void CardDeck::shuffle(){
    for (int i {0}; i < 500; ++i){
        swap(rand() % 52, rand() % 52);
    }
}

Card CardDeck::drawCard(){
    Card returnVal {cards[cards.size() - 1]};
    cards.pop_back();
    return returnVal;
}
