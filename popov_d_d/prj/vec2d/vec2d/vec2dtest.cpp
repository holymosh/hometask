#include "vec2d.h"
#include <iostream>
#include <sstream>

inline std::ostream& operator<<(std::ostream& ostrm, Vec2d& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Vec2d& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
 {
     using namespace std;
     istringstream istrm(str);
     Vec2d z;
     istrm >> z;
     if (istrm.good()) {
       cout << "Read success: " << str << " -> " << z << endl;
       } else {
        cout << "Read error : " << str << " -> " << z << endl;
     }
 return istrm.good();
 } 

int main()
{
	using namespace std;
	Vec2d a(7, 7);
	Vec2d b(9, 9);
	cout << a << " + " << b << (a + b) << endl;
	cout << a << " - " << b << (a - b) << endl;
	cout << b << " -= " <<a<<"=";
	b -= a;
	cout << b << " += " << a << "=";
	b += a;
	cout << b << endl;
	cout << b.x_ << " " << b.y_<<endl;
	cout << a << " == " << b <<":"<< (a == b)<< endl;
	cout<<a<<"*"<<b<<"="<<(a*b)<< endl;
	double k(2.0);
	cout << a << "*" << k << "=" << (a*k) << endl;
	cout << "a[0]=";
	cout << a[0]<< endl;
	cout << "a[1]=" << a[1]<<endl;
	cout << a << "<" << b << " result:" << (a < b) << endl;
	cout << a << "!=" << b << " result:" << (a != b) << endl;
    return 0;
}

