#ifdef _WIN32  
#include <Windows.h>
#endif

#include "std_lib_facilities.h"


int main()
{

	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif
	cout << "Hello, World!\n";

	keep_window_open();
}

