#include "vector.h"
#include <iostream>
Vector::Vector()
{
	pointer_ = new double[0];
	count_ = 0;
}

Vector::Vector(ptrdiff_t capacity)
{
	pointer_ = new double[capacity];
	count_=0;
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

Vector &Vector::operator=(const Vector &rhs) {
	if (this != &rhs) {
		delete[] pointer_;
		count_ = rhs.count_;
		pointer_ = new double[rhs.capacity_];
		for (int i = 0; i < count_; i++) {
			this->operator[](i) = rhs[i];
		}
	}
	return *this;
}

const double &Vector::operator[](const ptrdiff_t position) const {
	if (position >count_ ) {
		using namespace std;
		cout << "out of range";
		//throw std::out_of_range("Out of range in vector");
	}
	return *(pointer_ + position);
}


double & Vector::operator[](const ptrdiff_t position)
{
	if (position >count_)
	{
		using namespace std;
		cout << "out of range exception"<<endl;
		//throw std::out_of_range("Out of range in vector");
	}
	return *(pointer_ + position);
}

ptrdiff_t Vector::getSize() const
{
	return count_;
}

void Vector::resize(const ptrdiff_t size)
{
	if (size > count_)
	{
		double* new_Pointer = new double[size];
		for (ptrdiff_t i (0); i < count_; i++)
		{
			new_Pointer[i] = pointer_[i];
		}
		delete[] pointer_;
		pointer_ = new_Pointer;
		for (ptrdiff_t i(count_); i < size; ++i)
		{
			pointer_[i] = 0.00;
		}
		capacity_ = size;
		
	}
	else
	{
		count_ = size;
	}
	
}

void Vector::add(double value)
{
	if (count_ < capacity_)
	{
		this->operator[](count_) = value;
		count_ += 1;
	}
	
}

std::ostream & Vector::writeTo(std::ostream & ostrm)
{
	for (ptrdiff_t i = 0; i < count_; ++i) 
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

