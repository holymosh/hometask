#include <iostream>
#include "vector.h"

void runTests();

using namespace std;

int main() {

	cout << "create vector with size =10" << endl;
	Vector vector(10);
	double val(0.00);
	for (ptrdiff_t i(0); i < 10; ++i) {
		vector.add(val);
		val += 1.00;
	}
	cout << vector << endl << endl;
	double a = vector[1];
	cout << "vector[1]=" << a<<endl;

	try {
		cout << "try to get twelveth element " << endl;
		vector[20];
	}
	catch (out_of_range)
	{
		cout << "fail!" << endl;
	}

	cout << endl;

	cout << "create new vector and copy last vector to new vector" << endl;
	Vector newVector;
	newVector = vector;
	cout << newVector << endl;
	cout << endl;
	cout << "decrease size to 7 " << endl;
	newVector.resize(7);
	cout << newVector << endl;
	cout << endl;
	cout << "increase size to 10 " << endl;
	newVector.resize(10);
	newVector.add(7.99);
	newVector.add(8.99);
	newVector.add(10.87);
	cout << newVector << endl;
	int k;
	cin >> k;
	return 0;
}

