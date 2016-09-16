#include <iostream>
using namespace std;
void Nod(int firstValue, int secondValue) {
	int c;
	while (secondValue)
	{
		c = firstValue % secondValue;
		firstValue = secondValue;
		secondValue = c;
		
	}
	cout << firstValue;
}
int main()
{
	int firstValue = 8, secondValue = 16;
	Nod(firstValue, secondValue);

	
}