#include "rational.h"
#include <iostream>
#include <math.h>
#include <sstream>

Rational Rational::normalize( Rational& argument)
{
	int num(argument.num_);
	int denum(argument.denum_);
	while (num % denum != 0) {
		if (abs(num) < abs(denum)) std::swap(num, denum);
		if (num % denum != 0) num = num % denum;
	}
	num = argument.num_ / denum;
	denum = argument.denum_ / denum;
	Rational z(num, denum);
	return z;
}

Rational Rational::operator*(const Rational & rhs)
{
	return normalize(Rational(num_*rhs.num_, denum_*rhs.denum_));
}

Rational Rational::operator- (const Rational& rhs)
{
	return normalize(Rational(num_*rhs.denum_ - rhs.num_ * denum_, denum_ * rhs.denum_));
	Rational result(num_*rhs.denum_ - rhs.num_ * denum_, denum_ * rhs.denum_);
	return normalize(result);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << num_ << "/" << denum_ ;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream & istrm) 
{
	int num(0);
	int denum(0);
	char slash(0);
	istrm >> num >> slash >> denum;
	if (istrm.good())
	{
		if (slash == '/' && denum)
		{
			num_ = num;
			denum_ = denum;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}

	}
	return istrm;
}

Rational::Rational()
{
}

Rational::~Rational()
{
}

Rational::Rational(const int val)
{
	num_=val;
}

Rational::Rational(const int num, const int denum)
{
	if (!denum)
	{
		throw std::exception("denum = 0");

	}
	num_ = num;
	denum_ = denum;
}

double Rational::toDouble() const
{
	return num_ / denum_;
}

bool Rational::operator==(const Rational & rhs) const
{
	return (num_ == rhs.num_) && (denum_ == rhs.denum_);
}

bool Rational::operator!=(const Rational & rhs) const
{
	return !operator==(rhs);
}

Rational & Rational::operator=(const Rational & rhs)
{
	return Rational(num_ = rhs.num_, denum_ = rhs.denum_);
}

Rational Rational::operator+(const Rational & rhs)
{
	return normalize(Rational(num_*rhs.denum_ + rhs.num_ * denum_, denum_ * rhs.denum_));
}

Rational Rational::operator/(const Rational & rhs)
{
	return normalize(Rational(num_*rhs.denum_, denum_*rhs.num_));
}

Rational& Rational:: operator+=(const Rational& a) {
	num_ = num_*a.denum_ + a.num_ * denum_;
	denum_ = denum_ * a.denum_;
	return normalize(Rational(num_, denum_));
}

Rational& Rational:: operator-=(const Rational& rhs) {
	num_ = num_*rhs.denum_ - rhs.num_ * denum_;
	denum_ = denum_ * rhs.denum_;
	return normalize(Rational(num_, denum_));
}

Rational Rational:: operator/=(const Rational& rhs) {
	num_ = num_*rhs.denum_;
	denum_ = denum_*rhs.num_;
	return normalize(Rational(num_, denum_));
}

Rational Rational:: operator*=(const Rational& rhs) {
	num_ = num_*rhs.num_;
	denum_ = denum_ * rhs.denum_;
	return normalize(Rational(num_, denum_));
}

bool Rational::operator>(const Rational & rhs)
{
	return (num_*rhs.denum_ > rhs.num_*denum_);
}

bool Rational::operator<(const Rational & rhs)
{
	return (num_*rhs.denum_ < rhs.num_*denum_);
}

