
#include "std_lib_facilities.h"
#include "utilities.h"


int main()
{
	try{
	//writeToFile("utfil_a.txt");
	//addLineNum("utfil_a.txt", "utfil_b.txt");
	charStat("grunnlov.txt");
	keep_window_open();
	}
	catch(invalid_argument e){
		cerr << e.what();
		keep_window_open();
	}

	catch(...){
		cerr << "Noe gikk galt";
		keep_window_open();
	}
}
