
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

void inputAndPrintInteger(){
	int storedInteger {0};
	cout << "Skriv inn et tall: ";
	cin >> storedInteger;
	cout << "Du skrev: " << storedInteger << endl;
	cin.clear();
	return;
}

int inputInteger(){
	int storedInteger {0};
	cout << "Skriv inn et tall: ";
	cin >> storedInteger;
	return storedInteger;
}

void inputIntegersAndPrintSum(){
	int firstNumber {inputInteger()};
	int secondNumber {inputInteger()};
	cout << "Summen av tallene: " << firstNumber + secondNumber << endl;
	return;
}

bool isOdd(int test){
	bool odde {static_cast<bool> (test % 2)};
	return odde;
}

void printHumanReadableTime(int sekunder){
	int timer {sekunder / (60 * 60)}; // Dette er med vilje int, og vil føre til heltallsdivisjon.
	int minutter {(sekunder % (60 * 60)) / 60};
	sekunder = sekunder % 60;

	cout << timer << " Timer, " << minutter << " Minutter og " << sekunder << "Sekunder\n";
}

void nNumberSum(){
	cout << "Hvor mange tall vil du summere?\n";
	unsigned int n {0};
	cin >> n;
	int sum {0};
	for (unsigned int i {0}; i < n; ++i){
		int input {0};
		cout << "Tall " << i + 1 << ": ";
		cin >> input;
		sum += input;
	}
	cout << "Summen blir " << sum << endl;
	return;
}

void sumTillStop(){
	int sum {0};
	int inn {0};
	bool keepOn {true};
	do{
		cout << "Tall: \n";
		cin >> inn;
		if (inn == 0){
			keepOn = false;
		}
		else{
			sum += inn;
		}
	}
	while (keepOn);
	cout << "Summen blir " << sum << endl;
}

double inputDouble(){
	double storedFloat {0};
	cout << "Skriv inn et tall: ";
	cin >> storedFloat;
	return storedFloat;
}

void eurNokConvert(){
	constexpr double vekslingskurs {9.75};
	bool valid {false};
	double nok {0};

	while (!valid){
		nok = inputDouble();
		if (nok > 0){
			valid = true;
		}
	}
	double eur {nok / vekslingskurs};
	cout << setprecision(2) << fixed << eur  << endl;
	return;
}

void multiplicationTable(){
	int xValue {0}; int yValue{0};
	cout << "Hvor mange rader skal tabellen ha?\n";
	cin >> xValue;
	cout << "Hvor mange kolonner skal tabellen ha?\n";
	cin >> yValue;
	int maxValue = xValue * yValue;
	string tableWidthString {to_string(maxValue)};
	int tableWidth {static_cast<int>(tableWidthString.size())}; // Mulighet for å overskride maksimal int-verdi, men tabellen er så godt som uleselig lenge før det uansett.

	for (int i {1}; i <= yValue; ++i){
		for (int j {1}; j <= xValue; ++j){
			cout << setw(tableWidth + 1) << i * j;
		}
		cout << endl;
	}
}

double discriminant(double a, double b, double c){
	return (b * b) - (4 * a * c);
}

void printRealRoots(double a, double b, double c){
	double result1 {0}; double result2 {0}; int numSol {0};
	double rootExpression {discriminant(a, b, c)};
	if (rootExpression == 0){
		numSol = 1;
		result1 = -b / (2 * a);
	}
	else if (rootExpression < 0){
		numSol = 0;
	}
	else {
		numSol = 2;
		result1 = (-b + sqrt(rootExpression)) / (2 * a);
		result2 = (-b - sqrt(rootExpression)) / (2 * a);
	}

	cout << "Likningen har " << numSol << " løsninger.\n";
	if (numSol == 2){
		cout << "x = " << result1 << ", x = " << result2 << endl;
	}
	else if (numSol == 1){
		cout << "x = " << result1 << endl;
	}
	return;
}

void solveQuadraticEquation(){
	double a, b, c {0};
	cout << "Skriv inn tallene a, b og c i uttrykket ax^2+bx+c=0 for å løse uttrykket.\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "------------------------------------------" << endl << endl;

	printRealRoots(a, b, c);
	return;
}

void pythagoras(){
	using namespace Graph_lib;
	int windowHeight {500};
	int windowWidth {600};

	Simple_window win {Point{100, 100}, windowWidth, windowHeight, "Pythagoras"};

	// Making the centre triangle
	int lengA {4};
	int lengB {7};
	int lenModifier {25};
	Polygon rightTriangle;
	rightTriangle.add(Point{250, 300});
	rightTriangle.add(Point{250 + lengA * lenModifier, 300});
	rightTriangle.add(Point{250, 300 - lengB * lenModifier});
	rightTriangle.set_fill_color(Color::dark_red);
	rightTriangle.set_color(Color::dark_red);
	win.attach(rightTriangle);

	// Making the sqare on the a side
	Polygon aSquare;
	aSquare.add(Point{250, 300});
	aSquare.add(Point{250 + lengA * lenModifier, 300});
	aSquare.add(Point{250 + lengA * lenModifier, 300 + lengA * lenModifier});
	aSquare.add(Point{250, 300 + lengA * lenModifier});
	aSquare.set_color(Color::green);
	aSquare.set_fill_color(Color::green);
	win.attach(aSquare);

	// Making the square on the b side
	Polygon bSquare;
	bSquare.add(Point{250, 300});
	bSquare.add(Point{250, 300 - lengB * lenModifier});
	bSquare.add(Point{250 - lengB * lenModifier, 300 - lengB * lenModifier});
	bSquare.add(Point{250 - lengB * lenModifier, 300});
	bSquare.set_color(Color::blue);
	bSquare.set_fill_color(Color::blue);
	win.attach(bSquare);

	// Making the square on the c side
	Polygon cSquare;
	cSquare.add(Point{250, 300 - lengB * lenModifier});
	cSquare.add(Point{250 + lengA * lenModifier, 300});
	cSquare.add(Point{250 + (lengA + lengB) * lenModifier, 300 - lengA * lenModifier});
	cSquare.add(Point{250 + lengB * lenModifier, 300 - (lengA + lengB) * lenModifier});
	cSquare.set_fill_color(Color::cyan);
	cSquare.set_color(Color::cyan);
	win.attach(cSquare);


	win.wait_for_button();
	return;
}

vector<int> calculateSeries (int borrow, int rate, int years){
	vector<int> payment (years);
	int remainingBorrow {borrow};
	for (int i {0}; i < years; ++i){
		payment[i] = static_cast<int> (static_cast<double> (borrow) / years + static_cast<double> (rate) * remainingBorrow / 100);
		remainingBorrow -= borrow / years;
	}
	return payment;
}

vector<int> calculateAnnuity (int borrow, int rate, int years){
	vector<int> payment (years);
	int eachYear {static_cast<int> (static_cast<double>(borrow) * (rate / 100.0) / (1 - pow(1 + rate / 100.0, -(years))))};
	for (int i {0}; i < years; ++i){
		payment[i] = eachYear;
	}
	return payment;
}

void compareLoans (){
	cout << "Hvor stort er lånet?\n";
	int borrow {0};
	cin >> borrow;
	cout << "Hva er rentene på lånet?\n";
	int rate {0};
	cin >> rate;
	cout << "Hvor lang nedbetalingstid skal lånet ha? (I år)\n";
	int years {0};
	cin >> years;

	vector<int> annuityVec {calculateAnnuity(borrow, rate, years)};
	vector<int> seriesVec {calculateSeries(borrow, rate, years)};

	int annuityTotal {annuityVec[0] * years};
	int seriesTotal {0};
	for (int i {0}; i < years; ++i){
		seriesTotal += seriesVec[i];
	}

	int wFirstCol {max(static_cast<int>(log10(years)), 5) + 2};
	int wSecondCol {max(11, static_cast<int>(log10(annuityTotal))) + 2};
	int wThirdCol {max(5, static_cast<int> (log10(seriesTotal))) + 2};
	int wFourthCol {max(10, static_cast<int> (log10(abs(seriesTotal - annuityTotal))) + 3) + 2}; // +3 siden jeg ikke gidder å finne den største negative eller positive verdien differansen kan ha.
	cout << setw(wFirstCol) << "År" << setw(wSecondCol) << "Annuitet" << setw(wThirdCol) << "Serie" << setw(wFourthCol) << "Differanse" << endl;

	for (int i {0}; i < years; ++i){
		cout << setw(wFirstCol) << i + 1 << setw(wSecondCol) << annuityVec[i] << setw(wThirdCol) << seriesVec[i] << setw(wFourthCol) << annuityVec[i] - seriesVec[i] << endl;
	}
	cout << setw(wFirstCol) << "Total" << setw(wSecondCol) << annuityTotal << setw(wThirdCol) << seriesTotal << setw(wFourthCol) << annuityTotal - seriesTotal << endl;
	return;
}

int main()
{
//  Oppgave 1a
//	inputAndPrintInteger();

//  Oppgave 1b
//	int number {inputInteger()};
//	cout << "Du skrev: " << number << endl;

//  Oppgave 1c
//	inputIntegersAndPrintSum();

//  Oppgave 1d
//  Jeg valgte å bruke inputInteger fordi denne funksjonen returnerer et tall, og printer det ikke til skjermen.

//  Oppgave 1e
//	for (unsigned int i {0}; i < 16; ++i){
//		cout << i << ":\t" << isOdd(i) << endl;
//	}

//  Oppgave 1f
//	printHumanReadableTime(10000);

//  Oppgeve 2a
//	nNumberSum();

//  Oppgave 2b
//	sumTillStop();

//  Oppgave 2c
//	I b vet vi ikke hvor lang løkken blir, dermed passer while bra. Dette vet vi i oppgave c, og dermed passer en for-løkke.

//	Oppgave 2d
//	double fNumber {inputDouble()};
//	cout << "Du skrev: " << fNumber << endl;

//  Oppgave 2e
//	eurNokConvert();

//	Oppgave 2f
//	inputDouble kan håndtere desimaltall også, noe pengemengder overraskende ofte er. Bruker void, da resultatet bare skal skrives til skjerm. Da ville vi hatt en unødvendig variabel i programmet, og det liker vi ikke.

//  Oppgave 3a, 3b, 4d og 6c
	bool keepGoing {true};
	while (keepGoing){
		int innData {-1};
		cout << "Velg funksjon:\n0) Avslutt\n1) Summer to tall\n2) Summer flere tall\n3) Konverter NOK til EUR\n4) Lag en gangetabell\n5) Løs en andregradslikning\n6) Sammenlikn lån\n";
		cout << "Angi valg (0-6): ";
		cin >> innData;

		switch (innData){
		case 0:
			keepGoing = false;
			break;
		
		case 1:
			inputIntegersAndPrintSum();
			break;

		case 2:
			nNumberSum();
			break;

		case 3:
			eurNokConvert();
			break;

		case 4:
			multiplicationTable();
			break;
		
		case 5:
			solveQuadraticEquation();
			break;

		case 6:
			compareLoans();
			break;

		default:
			cout << "Dette var uforståelig, prøv igjen.";
		}

	}


//  Oppgave 4a
//	double a {2}; double b {10.2}; double c {3.2};
//	double result {discriminant(a, b, c)};
//	cout << result;

//  Oppgave 4b
//	printRealRoots(1.0, -3.0, -4.0);

//  Oppgave 4c
//	solveQuadraticEquation();

//  Oppgave 
	pythagoras();

//  Oppgave 6a
//	vector<int> result1 {calculateSeries(10000, 5, 10)};
//	for (unsigned int i{0}; i < result1.size(); ++i){
//		cout << result1[i] << endl;
//	}

//  Oppgave 6b
//	vector<int> result2 {calculateAnnuity(10000, 5, 10)};
//	for (unsigned int i{0}; i < result2.size(); ++i){
//		cout << result2[i] << endl;
//	}

	keep_window_open();
	return 0;
}


