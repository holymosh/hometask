#include "vec2d.h"
#include <iostream>

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
	a += b;
	cout << a.x_<<" "<< a.y_<<endl;
	b -= a;
	cout << b.x_ << " " << b.y_<<endl;
	cout << a*b<<endl;
	cout << a[0]<<endl;
	//cin >> a;
	system("pause");
    return 0;
}
