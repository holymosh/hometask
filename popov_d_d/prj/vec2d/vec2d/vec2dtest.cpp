#include "stdafx.h"
#include "vec2d.h"
#include <iostream>

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
	system("pause");
    return 0;
}

