
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	try{
	Card test{Suit::spades, Rank::ace};

	cout << test.toStringShort() << endl << endl;

	CardDeck teste {};

	teste.printShort();

	teste.shuffle();

	teste.printShort();

	playBlackjack();

	}

	catch(invalid_argument e){
		cerr << "noe gikk galt, " << e.what();
	}
	catch(...){
		cerr << "noe ukjent gikk galt.";
	}
	keep_window_open();
}