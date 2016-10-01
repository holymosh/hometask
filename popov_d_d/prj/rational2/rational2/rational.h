#ifndef HG_RATIONAL_H_20160926
#define HG_RATIONAL_H_20160926
#include <iostream>

class Rational
{
public:
	Rational();
	~Rational();
	explicit Rational(const int val) : num_(val) { }
	Rational(const int num, const int denum) : num_(num), denum_(denum) {}
	double toDouble() const;
	bool operator==(const Rational& rhs) const { return (num_ == rhs.num_) && (denum_ == rhs.denum_); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	Rational& operator= (const Rational& rhs) { return Rational(num_ = rhs.num_, denum_ = rhs.denum_); }
	Rational operator+ (const Rational& rhs) { return normalize(Rational(num_*rhs.denum_ + rhs.num_ * denum_, denum_ * rhs.denum_)); }
	Rational operator/(const Rational& rhs) { return normalize(Rational(num_*rhs.denum_, denum_*rhs.num_)); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational operator/=(const Rational& rhs);
	Rational operator*=(const Rational& a);
	bool operator>(const Rational& rhs) { return (num_*rhs.denum_ > rhs.num_*denum_); }
	bool operator<(const Rational& rhs) { return (num_*rhs.denum_ < rhs.num_*denum_); }
	Rational operator*(const Rational& rhs) { return normalize(Rational(num_*rhs.num_, denum_*rhs.denum_)); }
	Rational operator- (const Rational& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm) const;

private:
	int num_{ 0 };
	int denum_{ 1 };
	Rational normalize(const Rational argument);

};

Rational::Rational()
{
}

Rational::~Rational()
{
}
#endif