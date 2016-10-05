#include "stdafx.h"
#include "vec2d.h"
#include <iostream>

Vec2d& Vec2d::operator+=(const Vec2d& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}

Vec2d& Vec2d::operator-=(const Vec2d& rhs)
{
	x_ -= rhs.x_;
	y_ -= rhs.y_;
	return *this;
}

Vec2d& Vec2d::operator+(const Vec2d& rhs)
{
	return Vec2d(x_ + rhs.x_, y_ + rhs.y_);
}

Vec2d& Vec2d::operator-(const Vec2d& rhs)
{
	return Vec2d(x_ - rhs.x_, y_ - rhs.y_);
}

bool Vec2d::operator<(const Vec2d& rhs)
{
	return abs() - rhs.abs();
}

double Vec2d::operator*(const Vec2d& rhs)
{
	return x_*rhs.x_ + y_*rhs.y_;
}

double Vec2d::operator[](const int index) const
{
	if (!index)
	{
		return x_;
	}
	else if (index)return y_;
}

double Vec2d::abs() const
{
	return sqrt(x_*x_ + y_*y_);
}

Vec2d::Vec2d(const double x, const double y)
{
	x_ = x;
	y_ = y;
}

Vec2d::~Vec2d(){}

//std::ostream& Vec2d::writeTo(std::ostream& ostrm) const
//{
//
//}
//
//std::istream& Vec2d::readFrom(std::istream& istrm) const
//{
//
//}


