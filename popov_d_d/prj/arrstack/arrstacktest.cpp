#include "arrstack.h"
#include <iostream>
int  main()
{
	using namespace std;
	Stack stack(7);
	cout << "push seven elements to stack"<<'\n';
	for (ptrdiff_t i = 0; i < 7; i++)
	{
		cout << "push "<<i<<'\n';
		stack.push(i);
	}
	
	cout << stack;
	cout << "pop 3 elements" << '\n';
	for (int i(0); i < 3; i++)
	{
		int element = stack.pop();
		cout << "pop result " << element << '\n';
	}
	cout << "write current stack "<<'\n';
	cout << stack;
	cout << "get top: " << stack.getTop()<<'\n';
	cout << "peek 3 element = " << stack.peek(3)<<'\n';
	for (ptrdiff_t i = 8; i < 11; i++)
	{
		try
		{
			stack.push(i);
			cout << i << " pushed to stack \n";
		}
		catch (const std::exception&)
		{
			cout << "stack is full";
		}
	}
	cout << stack;
	cout << "create new stack by current stack and write this stack \n";
	Stack newStack(stack);
	cout << newStack;
	
	
	return 0;
}