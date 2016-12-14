#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>
#include "heatmaptypes.h"
using namespace cv;
class ValuesBuilder
{
public:
	ValuesBuilder()= default;
	ValuesBuilder(maptypes::maptype type);
	~ValuesBuilder();
	ValuesBuilder(const ValuesBuilder& other);
	Mat_<Scalar> getScalarMat(const Mat& values, maptypes::maptype mtype);
	maptypes::maptype maptype{maptypes::first};
private:
	Mat_<Scalar> createScalarMat(const Mat& values);
	Scalar createValue(int value);


};
#endif
