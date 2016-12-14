#ifndef HEATMAPBUILDER
#define HEATMAPBUILDER
#include <opencv2/core/mat.hpp>

class HeatMapBuilder
{
public:
	HeatMapBuilder()= default;
	HeatMapBuilder(const HeatMapBuilder& other);
	cv::Mat getUsualHeatMap(cv::Mat_<cv::Scalar>& scalars);

private:
};
#endif
