#include "iteratorTest.h"
#include <iostream>
#include "Templates.hpp"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	//iteratorTest();
	srand(time(nullptr));

	int a {1};
	int b {2};
	int c {maximum(a, b)};

	cout << c << endl;

	vector<int> vec {1,2,3,4,5,6,7,8,9,0};
	shuffle(vec);

	for (auto v : vec){
		cout << v << " ";
	}

	string l;
	cin >> l;
}
