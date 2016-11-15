#include "ArrStackT.h"

template<typename T, ptrdiff_t capacity>
StackArrT<T, capacity>::StackArrT(ptrdiff_t capacity) : data_ = new T[capacity], count_(0),capacity_(capacity)
{

}

template<typename T, ptrdiff_t capacity>
StackArrT<T, capacity>::~StackArrT()
{
	delete[] data_;
	data_ = nullptr;
}

template<typename T, ptrdiff_t capacity>
StackArrT<T, capacity>::StackArrT(StackArrT & obj)
{
	delete[] data_;
	data_ = new T[obj.capacity_];
	capacity_ = obj.capacity_;
	for (ptr i(0); i < obj.count_; i++)
	{
		data_[i] = obj.data_[i];
	}
	count_ = obj.count_;
}


template<typename T, ptrdiff_t capacity>
inline void StackArrT<T, capacity>::push(const T arg)
{
	if (size_ >= capacity_ )
	{
		throw std::exception("stack is full");
	}
	data_[count_] = arg;
	++count_;
}

template<typename T, ptrdiff_t capacity>
T StackArrT<T, capacity>::pop()
{
	if (count_==0)
	{
		throw std::exception("stack is empty");
	}
	T value(data_[count_]);
	--count_;
	
}

template<typename T, ptrdiff_t capacity>
T StackArrT<T, capacity>::top()
{
	if (count_==0)
	{
		throw std::exception("stack is empty");
	}
	return data_[count_];
}


