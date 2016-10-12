#include <iostream>
#include "rational.h"
#include <sstream>

std::ostream& operator<<(std::ostream& ostrm, const Rational& a) { return a.writeTo(ostrm); }
std::istream& operator>>(std::istream& istrm,  Rational& rhs) { return rhs.readFrom(istrm); }




int main()
{
	using namespace std;
	Rational a(10, 3);
	Rational b(1, 4);
	cout << a << "+" << b << "="<<(a + b) << endl;
	cout << a << "-" << b << "=" << (a - b) << endl;
	cout << a << "+=" << b << " result: ";
	a += b;
	cout << a << endl;
	cout << a << "-=" << b << " result: ";
	a -= b;
	cout << a << endl;
	cout << a << "*" << b << "=" << (a * b) << endl;
	Rational c(1, 4);
	Rational d(1, 3);
	cout << c << "*=" << d << " result: ";
	c *= d;
	cout << c << endl;
	cout << a << "<" << b << " result " << (a < b)<<endl;
	cout << a << ">" << b << " result " << (a > b) << endl;
	cout << a << "!=" << b << " result " << (a != b) << endl;
	cout << a << "==" << b << " result " << (a == b) << endl;
	cout << a << "==" << a << " result " << (a == a) << endl;
	cout << a << "/" << b << " result" << (a / b) << endl;
	int k(0);
	cin >> k;
	return 0;
}