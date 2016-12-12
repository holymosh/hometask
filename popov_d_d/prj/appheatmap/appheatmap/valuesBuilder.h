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
	Mat_<Scalar_<double>> getValuesMatrix(const Mat& values, maptypes::maptype mtype);
	maptypes::maptype maptype{maptypes::first};
private:
	Mat_<Scalar_<double>> getFirstScalarMatType(const Mat& values);
	Mat& getSecondScalarMatType(const Mat& values);
	Scalar& getFirstTypeScalarForValue(int value);


};
#endif
