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
	maptypes::maptype maptype{maptypes::first};
private:
	Mat& getSecondScalarMatType(const Mat& values);


};
#endif
