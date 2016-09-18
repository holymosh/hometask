#include <iostream>

using namespace std;

int nod(int firstValue, int secondValue)
{
	int localValue;
	while (secondValue)
	{
		localValue = firstValue % secondValue;
		firstValue = secondValue;
		secondValue = localValue;
		
	}
	return abs(firstValue);
}

void testNod() 
{
	int testValues[]{ 8,16,-9,-12 ,-5,-11,100,100};
	for (int i = 0; i < 8; i+=2)
	{
		cout << "nod(" << testValues[i] << "," << testValues[i+1] << ") : " << nod(testValues[i],testValues[i+1]) << "\n";
	}
	
}

int main()
{
	testNod();
	return 0;
}