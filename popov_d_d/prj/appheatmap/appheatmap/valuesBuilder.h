#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>
#include "heatmaptypes.h"

class ValuesBuilder
{
public:
	ValuesBuilder();
	ValuesBuilder(const ValuesBuilder& other);
	cv::Mat& getValuesMatrix( const cv::Mat& values , maptypes::maptype mtype  );

private:
};
#endif
