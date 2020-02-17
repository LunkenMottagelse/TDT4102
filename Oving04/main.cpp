
#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"




int main()
{
	using namespace Graph_lib;
	srand(static_cast<unsigned int>(time(nullptr)));

	testMenu();
	return gui_main();
}

