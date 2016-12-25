#ifndef HEATMAPBUILDER
#define HEATMAPBUILDER
#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>

class HeatMapBuilder
{
public:
	HeatMapBuilder()= default;
	cv::Mat createHeatMap(cv::Mat scalars);
};

#endif
