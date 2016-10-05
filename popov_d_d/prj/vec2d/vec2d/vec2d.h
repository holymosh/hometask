#ifndef HG_VEC2D_H_20160310
#define HG_VEC2D_H_20160310

#include <cmath>
class Vec2d
{
public:
	Vec2d();
	Vec2d(const double x, const double y);
	~Vec2d();
	double x_{ 0 };
	double y_{ 0 };
	double abs() const;
	Vec2d& operator+=(const Vec2d& rhs);
	Vec2d& operator-=(const Vec2d& rhs);
	Vec2d& operator+(const Vec2d& rhs);
	Vec2d& operator-(const Vec2d& rhs);
	Vec2d operator/=(const Vec2d& rhs);
	double operator[](const int index) const;
	double operator*(const Vec2d& rhs);
	bool operator<(const Vec2d& rhs);
	/*std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm) const;*/

private:

};


#endif
