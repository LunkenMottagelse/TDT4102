

#include "std_lib_facilities.h"

// Oppgave 1 a
/*
def isFibonacciNumber (n):
	a = 0
	b = 1
	while b < n:
		temp = b
		b += a
		a = temp 
	return b == n
*/

// Oppgave 2 a

double maxOfTwo(double a, double b){
	double returnValue{0};
	if (a > b){
		cout << "A is greater than B";
		returnValue = a;
	}
	else{
		cout << "B is greater than or equal to A";
		returnValue = b;
	}
	return returnValue;
}

// Oppgave 2 c

int fibonacci(int n){
	int a {0};
	int b {1};
	cout << "Fibonacci numbers:\n";

	int temp {0};
	for (int i {1}; i < n + 1; ++i){
		cout << i << ' ' << b << '\n';
		temp = b;
		b += a;
		a = temp;
	}
	cout << "---\n";
	return b;
}

// Oppgave 2 d

int squareNumberSum(int n){
	int totalSum {0};
	for (int i = 0; i < n; ++i){
		totalSum += i * i;
		cout << i * i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

// Oppgave 2 e

void triangleNumbersBelow(int n){
	int acc {1};
	int num {2};
	cout << "Triangle numbers below " << n << ": ";
	while (acc < n){
		cout << acc << endl;
		acc += num;
		++num;
	}
	cout << endl;
}

// Oppgave 2 f

bool isPrime(int n){
	bool prime {true};
	for (int j {2}; j < n; ++j){
		if (n % j == 0){
			prime = false;
			break;
		}
	}
	return prime;
}

// Oppgave 2 g

void naivePrimeNumberSearch(int n){
	for (int number {2}; number < n; ++number){
		if (isPrime (number)){
			cout << number << " is a prime\n";
		}
	}
}

// Oppgave 2 h

int findGreatestDivisor(int n){
	for (int divisor {n - 1}; divisor > 0; --divisor){
		if (n % divisor == 0){
			return divisor;
		}
	}
	return 0;
}


// Oppgave 2 b i tillegg til testkode fra andre oppgaver

int main(){
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << '\n';
	cout << "-----------------------------\n";
	
	int storedValue {fibonacci(5)};
	cout << "-----------------------------\n";

	storedValue = squareNumberSum(4);
	cout << "-----------------------------\n";

	triangleNumbersBelow(10);
	cout << "-----------------------------\n";
	
	cout << "6: " << isPrime(6) << " 17: " << isPrime(17) << "\n-----------------------------\n";

	naivePrimeNumberSearch(200);
	cout << "-----------------------------\n";

	cout << "Greatest divisor of 148: " << findGreatestDivisor(148);

	keep_window_open();

}


