
#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand,double toOperand,double maxError, string name);


int main(){
	try{
	//double maxError {0.001};
	//testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
	//cout << targetPractice(40, 20, 10);
	/*srand(static_cast<unsigned int>(time(nullptr)));
	for (int i{0}; i < 40; ++i){
		cout << randomWithLimits(34, 27) << endl;
	}
	*/
	playTargetPractice();
	keep_window_open();
	}
	catch(const invalid_argument& e){
		cerr << "Bad input, " << e.what();
	}
	catch(...){
		cerr << "Unknown error!";
	}
	return 0;
}


void testDeviation(double compareOperand,double toOperand,double maxError, string name){
	double error { compareOperand - toOperand };
	if (error >= -maxError && error <= maxError){
		cout << name << " passed.\n";
	}
	else{
		cout << name << " failed.\n";
	}
	return;
}