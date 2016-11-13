#include "arrstack.h"


Stack::Stack(ptrdiff_t size) : size_(size),top_(0)
{
	stackPointer_ = new int[size];
}

Stack::Stack(Stack & stack)
{
	delete[] stackPointer_;
	stackPointer_ = new int[stack.size_];
	for (ptrdiff_t i(0); i < stack.top_; ++i)
	{
		stackPointer_[i] = stack.stackPointer_[i];
	}
	size_ = stack.size_;
	top_ = stack.top_;
}

Stack::~Stack()
{
	delete[] stackPointer_;
}

void Stack::push(const int element)
{
	if (top_>size_)
	{
		throw std::exception("stack is full");
	}
	else
	{
		stackPointer_[top_] = element;
		++top_;
	}
}

int& Stack::pop()
{
	if (top_ > 0)
	{
		--top_;
		return *(stackPointer_ + top_ );
	}
	else
	{
		throw new std::exception();
	}
}

int Stack::peek(ptrdiff_t number)
{
	if (number <= top_)
	{
		return *(stackPointer_ + number);
	}
	else
	{
		throw new std::exception("number >= top");
	}
}


int Stack::getTop() const
{
	return top_;
}

std::ostream & Stack::writeTo(std::ostream & ostrm)
{
	for (ptrdiff_t i = 0; i < top_; ++i)
	{
		ostrm << *(stackPointer_ + i) << " ";
	}
	using namespace std;
	cout << endl;
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, Stack& obj)
{
	return obj.writeTo(ostrm);
}
