#ifndef HEATMAPBUILDER
#define HEATMAPBUILDER
#include <opencv2/core/mat.hpp>

class HeatMapBuilder
{
public:
	HeatMapBuilder()= default;
	cv::Mat createHeatMap(cv::Mat_<cv::Scalar>& scalars);
};
#endif
