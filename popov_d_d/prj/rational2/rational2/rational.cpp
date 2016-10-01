#include <cstdint>
#include <iostream>
#include <sstream>
#include "rational.h"

Rational Rational::normalize(const Rational argument)
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

Rational Rational::operator- (const Rational& rhs) 
{
	return normalize(Rational(num_*rhs.denum_ - rhs.num_ * denum_, denum_ * rhs.denum_));
	Rational result(num_*rhs.denum_ - rhs.num_ * denum_, denum_ * rhs.denum_);
	return normalize(result);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << num_ << "/" << denum_ << "\n";
	return ostrm;
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

 std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
 std::istream& operator>>(std::istream& istrm, const Rational& rhs) { return rhs.readFrom(istrm); }

//int main() {
//	using namespace std;
//	Rational a(10, 11);
//	Rational b(1, 11);
//	Rational c(a + b);
//	cout << "a=" << a << " b="<<b<< endl;
//	cout << "a+b=" << c;
//	a += b;
//	cout << "a+=b =" << a;
//	cout << "a=" << a << " b=" << b << endl;
//	c = a - b;
//	cout << "a-b=" << c;
//	a -= b;
//	cout << "a-=b =" << a;
//	c = a*b;
//	cout << "a=" << a << " b=" << b << endl;
//	cout << "a*b=" << c;
//	a *= b;
//	cout << "a*=b =" << a;
//	system("pause");
//};