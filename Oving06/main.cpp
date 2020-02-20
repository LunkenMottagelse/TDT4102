#ifdef _WIN32  
#include <Windows.h>
#endif

#include "std_lib_facilities.h"
#include "utilities.h"
#include "temps.h"

int main()
{
	try{
	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif
	//writeToFile("utfil_a.txt");
	//addLineNum("utfil_a.txt", "utfil_b.txt");
	/*charStat("grunnlov.txt");
	
	CourseCatalog nrEn {};
	nrEn.addCourse("TDT4102", "Objektorientert proggramering");
	nrEn.addCourse("TMA4115", "Matte 3");
	nrEn.addCourse("TMA4105", "Matte 2");
	nrEn.addCourse("TDT4102", "C++");

	cout << "En oversikt: \n" << nrEn << "\n Lagrer data i courseData.txt...\n";

	nrEn.writeData("courseData.txt");

	cout << "Henter data fra courseData.txt...\n";

	CourseCatalog nrTo {};
	nrTo.loadData("courseData.txt");

	cout << "Data fra filen:\n" << nrTo;*/

	//tempsAsVec("temperatures.txt");

	graphicalRepresentation();
	
	keep_window_open();
	}
	catch(invalid_argument e){
		cerr << e.what() << endl;
		keep_window_open();
	}

	catch(...){
		cerr << "Noe gikk galt, " << endl;
		keep_window_open();
	}
}
