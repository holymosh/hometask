#include <iostream>
using namespace std;
int Nod(int firstValue, int secondValue) {
	int c;
	while (secondValue)
	{
		c = firstValue % secondValue;
		firstValue = secondValue;
		secondValue = c;
		
	}
	return abs(firstValue);
}
int main()
{
	int firstValue = 8, secondValue = 16;
	cout<<"nod(8,16) :"<<Nod(firstValue, secondValue)<<"\n";
	firstValue = -9, secondValue = 12;
	cout << "nod(-9,12) :" << Nod(secondValue, firstValue) << "\n";
	firstValue = -11, secondValue = -5;
	cout << "nod(-5,-11) :" << Nod(secondValue, firstValue) << "\n";
	firstValue = 100, secondValue = 100;
	cout << "nod(100,100) :" << Nod(secondValue, firstValue) << "\n";
	return 0;
	
}