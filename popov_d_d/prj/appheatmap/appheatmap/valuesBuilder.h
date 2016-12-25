#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>
using namespace cv;
class ValuesBuilder
{
public:
	ValuesBuilder()= default;
	~ValuesBuilder();
	Mat getScalarMat(Mat& values);
private:
	Mat_<Scalar> createScalarMat(Mat& values);
	Scalar createValue(int value);
	Scalar createValuetest(int value, int min, int max);


};
extern "C" CvMat create_Cvmat(CvMat* cv_mat);
#endif
