#include "std_lib_facilities.h"
#include "Card.h"

string suitToString(const Suit& suit){
    map<Suit, string> mapping {{Suit::spades, "Spades"}, {Suit::clubs, "Clubs"}, {Suit::diamonds, "Diamonds"}, {Suit::hearts, "Hearts"}};
    return mapping[suit];
}

string rankToString(const Rank& rank){
    map<Rank, string> mapping {{Rank::ace, "Ace"}, {Rank::eight, "Eight"}, {Rank::five, "Five"}, {Rank::four, "Four"}, {Rank::two, "Two"}, {Rank::three, "Three"}, {Rank::six, "Six"}, {Rank::seven, "Seven"}, {Rank::nine, "Nine"}, {Rank::ten, "Ten"}, {Rank::jack, "Jack"}, {Rank::queen, "Queen"}, {Rank::king, "King"}};
    return mapping[rank];
}

Card::Card(Suit suit, Rank rank) : s{suit}, r{rank} {

}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    string out {""};

    out += rankToString(r);
    out += " of ";
    out += suitToString(s);

    return out;
}
string Card::toStringShort(){
    string out {""};
    string suitString {suitToString(s)};
    out += suitString[0];
    int cardNum {static_cast<int>(r)};
    out += to_string(cardNum);
    return out;
}

