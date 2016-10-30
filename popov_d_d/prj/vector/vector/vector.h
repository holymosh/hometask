#ifndef HG_VECTOR_H_20161017
#define HG_VECTOR_H_20161017


#include <iostream>

class Vector {

public:
	Vector();
	Vector(ptrdiff_t size);
	Vector(const Vector& vector);
	~Vector();
	Vector& operator= (const Vector& rhs);
	const double &Vector::operator[](const ptrdiff_t idx) const;
	double& operator[](const ptrdiff_t position);
	ptrdiff_t getSize() const;
	void resize(const ptrdiff_t size);
	void add(double value);
	std::ostream& writeTo(std::ostream& ostrm);

private:
	ptrdiff_t count_{ 0 };
	double* pointer_{ nullptr };
	ptrdiff_t capacity_{ 0 };

};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);


#endif