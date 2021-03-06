#ifndef HG_RATIONAL_H_20160926
#define HG_RATIONAL_H_20160926

#include <iosfwd>
class Rational
{
public:
	Rational();
	~Rational();
	explicit Rational(const int val);
	Rational(const int num, const int denum);
	double toDouble() const;
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	Rational& operator= (const Rational& rhs);
	Rational operator+ (const Rational& rhs);
	Rational operator/(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational operator/=(const Rational& rhs);
	Rational operator*=(const Rational& a);
	bool operator>(const Rational& rhs);
	bool operator<(const Rational& rhs);
	Rational operator*(const Rational& rhs);
	Rational operator- (const Rational& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm) ;
	
private:
	
	Rational normalize( Rational& argument);
	int num_{ 0 };
	int denum_{ 1 };

};

#endif