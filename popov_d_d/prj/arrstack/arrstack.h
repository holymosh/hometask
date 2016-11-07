#ifndef STACKBYHOLYMOSH
#define STACKBYHOLYMOSH

#include <iostream>
class Stack
{
public:
	Stack() = default;
	Stack(ptrdiff_t size);
	Stack(Stack& stack);
	~Stack();
	void push(const int element);
	int pop();
	int peek(ptrdiff_t number);
	int getTop() const;
	std::ostream& writeTo(std::ostream& ostrm);
private:
	int* stackPointer_{nullptr};
	ptrdiff_t size_{0};
	ptrdiff_t top_{-1};
};

std::ostream& operator<<(std::ostream& ostrm, Stack& obj);

#endif 
