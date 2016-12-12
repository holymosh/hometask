#include "valuesBuilder.h"

using namespace cv;

ValuesBuilder::ValuesBuilder(maptypes::maptype type)
{
	maptype = type;
}

ValuesBuilder::~ValuesBuilder()
{
}

ValuesBuilder::ValuesBuilder(const ValuesBuilder& other)
{
}

Mat_<Scalar> ValuesBuilder::getValuesMatrix(const Mat& values, maptypes::maptype mtype)
{
	Mat_<Scalar> scalarMat(values.rows, values.cols, DataType<Scalar>::type);
	switch (mtype)
	{
	case maptypes::first:
		return getFirstScalarMatType(values);
	case maptypes::second: 
		scalarMat = getSecondScalarMatType(values);
		return scalarMat;
	default: break;
	}
}

Mat_<Scalar> ValuesBuilder::getFirstScalarMatType(const Mat& values)
{
	Mat_<Scalar> scalarMat(values.rows , values.cols , DataType<Scalar>::type);
	for (int i = 0; i < values.rows; ++i)
	{
		for (int j = 0; j < values.cols; ++j)
		{
			scalarMat.at<Scalar>(i, j) = getFirstTypeScalarForValue(values.at<int>(i, j));
		}
	}
	return scalarMat;
}

Mat& ValuesBuilder::getSecondScalarMatType(const Mat& values)
{
	return Mat();
}

Scalar& ValuesBuilder::getFirstTypeScalarForValue(int value)
{
	double red(0);
	double green(0);
	double blue(255);
	for (int i(-20); i < value; ++i)
	{
		if (i < 0)
		{
			blue -= 12.75;
		}
		if (!i)
		{
			green = 255;
			blue = 0;
		}
		if (i && i<4 && i>0)
		{
			green -= 63.75;
		}
		if (i==5)
		{
			green = 255;
			red = 255;
		}
		if (i>6)
		{
			green -= 18.214;
		}
	}
	//return Scalar(0, 255, 255);
	return Scalar(blue, green, red);
}
