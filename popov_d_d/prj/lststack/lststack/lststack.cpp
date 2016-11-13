#include "lststack.h"
#include <iostream>

LstStack::LstStack(LstStack & obj)
{
	if (nullptr == obj.head_) return;
	head_ = new Node{ obj.head_->data_, nullptr };
	Node* pRead{ obj.head_->pNext_ };
	Node* pTail{ head_ };

	while (pRead != nullptr)
	{
		pTail->pNext_ = new Node{ pRead->data_, nullptr };

		pTail = (*pTail).pNext_;
		pRead = (*pRead).pNext_;
	}
}

LstStack::~LstStack()
{
	deleteAll();
}

double LstStack::pop()
{
	if (isEmpty())
	{
		throw std::exception("stack is empty");
	}
	double tmp = top();
	remove();
	return tmp;
}

bool LstStack::isEmpty()
{
	return (*head_).pNext_ == nullptr;
}

void LstStack::push(const double value)
{
	head_ = new Node{ value, head_ };
}

double LstStack::top() 
{
	if (isEmpty())
	{
		throw std::exception("stack is empty");
	}
	return (*head_).data_;
}

void LstStack::remove()
{
	if (isEmpty())
	{
		throw std::exception("stack is empty");
	}
	Node* tmp{ (*head_).pNext_};
	delete(head_);
	head_ = tmp;
}

void LstStack::deleteAll()
{
	while (!isEmpty())
		remove();
	delete(head_);
}
