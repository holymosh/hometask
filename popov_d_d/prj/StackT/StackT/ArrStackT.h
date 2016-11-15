#ifndef ARR_STACK_T_BY_HOLYMOSH
#define ARR_STACK_T_BY_HOLYMOSH
#include <iostream>

template <typename T , ptrdiff_t capacity>
class StackArrT
{
public:
	StackArrT() = default;
	StackArrT(const ptrdiff_t size);
	~StackArrT();
	StackArrT(StackArrT& obj);

	void push(const T arg);
	T pop();
	T top();

private:
	T* data_{ nullptr };
	ptrdiff_t count_{ 0 };
	ptrdiff_t capacity_{ 0 };
};


#endif
