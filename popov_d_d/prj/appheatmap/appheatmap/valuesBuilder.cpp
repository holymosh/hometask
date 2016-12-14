#include "valuesBuilder.h"
#include <opencv2/highgui.hpp>

using namespace cv;

ValuesBuilder::ValuesBuilder(maptypes::maptype type):maptype(type)
{
}

ValuesBuilder::~ValuesBuilder()
{
}

ValuesBuilder::ValuesBuilder(const ValuesBuilder& other):maptype(other.maptype)
{
	
}

Mat_<Scalar> ValuesBuilder::getScalarMat(const Mat& values, maptypes::maptype mtype)
{
	Mat_<Scalar> scalarMat(values.rows, values.cols, DataType<Scalar>::type);
		 scalarMat = createScalarMat(values);
		 return scalarMat;
}

Mat_<Scalar> ValuesBuilder::createScalarMat(const Mat& values)
{
	Mat_<Scalar> neededMat(values.rows, values.cols, DataType<Scalar>::type);
	for (int i = 0; i < neededMat.rows; ++i)
	{
		for (int j = 0; j < neededMat.cols; ++j)
		{
			neededMat.at<Scalar>(j, i) = createValue(values.at<int>(i, j));
		}
	}
	return neededMat.clone();
}

Scalar ValuesBuilder::createValue(int value)
{
	double red(0);
	double green(0);
	double blue(0);
	for (int i(-20); i < value; ++i)
	{
		if (i < 0)
		{
			blue += 12.75;
		}
		if (!i)
		{
			green = 255;
			blue = 0;
		}
		if (i && i<=4)
		{
			green -= 63.75/2;
		}
		if (i==5)
		{
			green = 255-2*18.214;
			red = 255;
		}
		if (i>=6)
		{
			green -= 18.214;
		}

	}
	return Scalar(blue, green, red);
}
