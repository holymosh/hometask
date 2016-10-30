#include "vector.h"
#include <iostream>
Vector::Vector()
{
	pointer_ = new double[0];
	size_ = 0;
}

Vector::Vector(ptrdiff_t capacity)
{
	pointer_ = new double[capacity];
	size_=0;
	capacity_ = capacity;
}

Vector::Vector(const Vector & vector)
{
	*this = vector;
}

Vector::~Vector()
{
	delete[] pointer_;
}

Vector & Vector::operator=(const Vector & rhs)
{
	if (this != &rhs) {
		if (capacity_ > rhs.getSize())
		{
			ptrdiff_t newSize = rhs.getSize();
			for (ptrdiff_t i = size_; i < newSize; i++)
			{
				*(pointer_ + i) = rhs[i];
			}
			size_ = newSize;
		}
		else
		{
			capacity_=rhs.capacity_;
			delete[] pointer_;
			pointer_ = rhs.pointer_;
		}
		}
	
	return *this;
}

const double &Vector::operator[](const ptrdiff_t rhs) const {
	if (rhs >= capacity_) {
		throw std::out_of_range("Out of range in vector");
	}
	return *(pointer_ + rhs);
}


double & Vector::operator[](const ptrdiff_t position)
{
	if (position >= capacity_) 
	{
		using namespace std;
		cout << "out of range exception"<<endl;
		//throw std::out_of_range("Out of range in vector");
	}
	++size_;
	return *(pointer_ + position);
}

ptrdiff_t Vector::getSize() const
{
	return size_;
}

void Vector::resize(const ptrdiff_t size)
{
	if (size > size_) 
	{
		Vector tmp{ *this };
		pointer_ = new double[size];
		*this = tmp;
		this->size_ = size_;
	}
	size_ = size;
}

std::ostream & Vector::writeTo(std::ostream & ostrm)
{
	for (ptrdiff_t i = 0; i < size_; ++i) 
	{
		ostrm << *(pointer_+i) << " ";
	}
	using namespace std;
	cout << endl;
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, Vector& obj)
{
	obj.writeTo(ostrm);
	return ostrm;
}

