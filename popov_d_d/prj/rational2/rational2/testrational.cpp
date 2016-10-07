#include <iostream>
#include "rational.h"

std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
std::istream& operator>>(std::istream& istrm, const Rational& rhs) { return rhs.readFrom(istrm); }


int main()
{
	using namespace std;
	Rational a(10, 11);
	Rational b(1, 11);
	Rational c(a + b);
	cout << "a=" << a << " b=" << b << endl;
	cout << "a+b=" << c;
	a += b;
	cout << "a+=b =" << a;
	cout << "a=" << a << " b=" << b << endl;
	c = a - b;
	cout << "a-b=" << c;
	a -= b;
	cout << "a-=b =" << a;
	c = a*b;
	cout << "a=" << a << " b=" << b << endl;
	cout << "a*b=" << c;
	a *= b;
	cout << "a*=b =" << a;
	cout << a << "<" << b << " result" << (a < b)<<endl;
	cout << a << ">" << b << " result" << (a > b) << endl;
	cout << a << "!=" << b << " result" << (a != b) << endl;
	cout << a << "==" << b << " result" << (a == b) << endl;
	cout << a << "/" << b << " result" << (a / b) << endl;
	cout << a << "/=" << b << " result" << (a /= b) << endl;
	return 0;
}