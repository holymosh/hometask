#include "valuesBuilder.h"

ValuesBuilder::ValuesBuilder()
{
}

ValuesBuilder::ValuesBuilder(const ValuesBuilder& other)
{
}

cv::Mat& ValuesBuilder::getValuesMatrix(const cv::Mat& values, maptypes::maptype mtype)
{
	switch (mtype)
	{
	case maptypes::first:
		break;
	case maptypes::second: 
		break;
	default: break;
	}
}
