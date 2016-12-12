#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>

class ValuesBuilder
{
public:
	ValuesBuilder();
	ValuesBuilder(const ValuesBuilder& other);
	cv::Mat& getValuesMatrix( const cv::Mat& values);

private:
};
#endif
