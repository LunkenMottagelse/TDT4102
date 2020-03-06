#ifdef _WIN32  
#include <Windows.h>
#endif

#include "std_lib_facilities.h"
#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"


int main()
{

	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif
/*	const Person nr1{"Torstein Holmengen", "torsho@stud.ntnu.no"};
	Car bil1 {3};
	Car* carptr;
	carptr = &bil1;
	const Person nr2{"Jørgen Molstad", "jorgmo@stud.ntnu.no", carptr};

	Meeting mote {15, 14, 16, Campus::Trondheim, "Reiseregningsjuks 101", &nr1};
	mote.addParticipant(&nr2);

	const Person nr3{"Mazyar Kehvari", "e.post@mail.no"};
	mote.addParticipant(&nr3);

	cout << nr1 << endl << nr2 << endl;
	cout << endl << endl;

	cout << Campus::Trondheim << endl;

	cout << endl << mote << endl;

	const Person nr4{"sdf", "flsjkd"};
	Meeting mote2{15, 13, 16, Campus::Trondheim, "dsf", &nr4};

	vector<const Person*> res {mote2.findPotentialCoDriving()};

*/
	MeetingWindow win {Point{100, 100}, 700, 600, "Canvas"};

	gui_main();

	win.printPerson();

	keep_window_open();
	return 0;
}

