#include "lststack.h"
#include <iostream>

int main() 
{
	using namespace std;
	LstStack stack;
	cout << "3.3 , 3.4 , 3.6 \n";
	stack.push(3.3);
	stack.push(3.4);
	stack.push(3.6);
	cout<<"top - " << stack.top()<<'\n';
	cout << stack.pop();
	cout << " removed \n";
	cout<<"top is " << stack.top() << '\n';
	return 0;
}