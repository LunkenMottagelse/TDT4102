#ifdef _WIN32  
#include <Windows.h>
#endif

#include <iostream>
#include "memoryHandling.h"
#include "Matrix.h"
#include "dummy.h"

using namespace std;

int main()
{

	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif

	try{
	cout << "Hello, World!\n";

	Matrix A {2};
	A.set(1, 1, 1.0);
	A.set(1, 2, 2.0);
	A.set(2, 1, 3.0);
	A.set(2, 2, 4.0);
	cout << A << endl;

	Matrix B {2};
	B.set(1, 1, 4.0);
	B.set(1, 2, 3.0);
	B.set(2, 1, 2.0);
	B.set(2, 2, 1.0);
	cout << B << endl;

	Matrix C {2};
	C.set(1, 1, 1.0);
	C.set(1, 2, 3.0);
	C.set(2, 1, 1.5);
	C.set(2, 2, 2.0);
	cout << C << endl;

	A += B + C;
	cout << A << endl << B << endl << C;


	//dummyTest();

	// Kodesnutt for å se resultatene:
	double f;
	std::cin >> f;
	return 0;
	}
	catch(...){
		cerr << "Error";
		int f;
		cin >> f;
	}
}

