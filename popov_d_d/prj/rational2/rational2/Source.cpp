#include <iostream>
#include <sstream>

using namespace std;

class Rational
{
public:
	Rational();
	Rational(int val):num_ (val){}
	Rational(int num , int denum):num_(num) ,denum_(denum){}
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	static const char slash{'/'};
	~Rational();

	double toDouble()
	{
		if (denum_) {
			return num_ / denum_;
		}
	}
	
	Rational& operator*(Rational& obj)
	{
		int denum(denum_ * obj.denum_);
		int num(num_ * obj.num_);
		return Rational(num, denum);
	}
	Rational& operator+=(const Rational& rhs);

private:
	int num_{ 0 };
	int denum_{ 1 };
};

std::istream& Rational::readFrom(std::istream& istrm)
{
	char slash('/');
	int num(0);
	int denum(1);
	istrm >> num >> slash >> denum;
	if (istrm.good())
	{
		if (Rational::slash == slash)
		{
			num_ = num;
			denum_ = denum;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
}

std::ostream& Rational:: writeTo(std::ostream& ostrm)  const
	{
		ostrm << num_ << "/" << denum_;
		return ostrm;
	}

	inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) 
	{
		return rhs.writeTo(ostrm);
	}

Rational::Rational()
{
}

Rational::~Rational()
{
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num_ += rhs.num_;
	denum_ += rhs.denum_;
	return *this;
}

Rational& operator-=(const Rational& lhs, const Rational rhs) 
{
	Rational sum(lhs - rhs);
}


//Rational& Rational::operator*=(const Rational& rhs)
//{
//	1
//}

Rational operator+(const Rational& lhs , const Rational rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}


int main()
{
	Rational first(1,2);
	Rational second(3, 4);
	Rational sum(first + second);
	cout << sum;
	return 0;
}