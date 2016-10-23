#include "vector.h"
#include <iostream>
Vector::Vector()
{
	pointer_ = new double[0];
	size_ = 0;
}

Vector::Vector(ptrdiff_t size)
{
	pointer_ = new double[size];
	size_ = size;
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
		delete[] pointer_;
		size_ = rhs.size_;
		pointer_ = new double[size_];
		for (int i = 0; i < size_; i++) {
			this->operator[](i) = rhs[i];
		}
	}
	return *this;
}

double & Vector::operator[](const ptrdiff_t position)
{
	if (position >= size_) 
	{
		using namespace std;
		cout << "out of range exception"<<endl;
		throw std::out_of_range("Out of range in vector");
	}
	return *(pointer_ + position);
}

const double & Vector::operator[](const ptrdiff_t position) const
{
	if (position >= size_)
	{
		using namespace std;
		cout << "out of range exception";
		throw std::out_of_range("Out of range in vector");
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

std::ostream & Vector::writeTo(std::ostream & ostrm)
{
	for (int i = 0; i < size_; ++i) 
	{
		ostrm << (*this)[i] << " ";
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

