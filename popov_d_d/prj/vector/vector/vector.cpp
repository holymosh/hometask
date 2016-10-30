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

Vector &Vector::operator=(const Vector &rhs) {
	if (this != &rhs) {
		delete[] pointer_;
		size_ = rhs.size_;
		pointer_ = new double[size_];
		for (int i = 0; i < size_; i++) {
			this->operator[](i) = rhs[i];
		}
	}
	return *this;
}

const double &Vector::operator[](const ptrdiff_t position) const {
	if (position >size_ ) {
		using namespace std;
		cout << "out of range";
		//throw std::out_of_range("Out of range in vector");
	}
	return *(pointer_ + position);
}


double & Vector::operator[](const ptrdiff_t position)
{
	if (position >size_)
	{
		using namespace std;
		cout << "out of range exception"<<endl;
		//throw std::out_of_range("Out of range in vector");
	}
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

void Vector::add(double value)
{
	if (size_ < capacity_)
	{
		this->operator[](size_) = value;
		size_ += 1;
	}
	
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

