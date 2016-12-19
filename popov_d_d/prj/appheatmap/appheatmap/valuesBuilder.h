#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>
using namespace cv;
class ValuesBuilder
{
public:
	ValuesBuilder()= default;
	
	~ValuesBuilder();
	ValuesBuilder(const ValuesBuilder& other);
	Mat_<Scalar> getScalarMat(const Mat& values);
private:
	void checkValues(Mat_<int>& values);
	Mat_<Scalar> createScalarMat(const Mat& values);
	Scalar createValue(int value);


};
#endif
