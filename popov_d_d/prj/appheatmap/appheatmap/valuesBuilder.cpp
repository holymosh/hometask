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

Mat_<Scalar> ValuesBuilder::getValuesMatrix(const Mat& values, maptypes::maptype mtype)
{
	Mat_<Scalar> scalarMat(values.rows, values.cols, DataType<Scalar>::type);
	switch (mtype)
	{
	case maptypes::first:
		 scalarMat = getFirstScalarMatType(values);
		 return scalarMat;
	case maptypes::second: 
		scalarMat = getSecondScalarMatType(values);
		return scalarMat;
	default: break;
	}
}

Mat_<Scalar> ValuesBuilder::getFirstScalarMatType(const Mat& values)
{
	Mat_<Scalar> neededMat(values.rows, values.cols, DataType<Scalar>::type);
	for (int i = 0; i < neededMat.rows; ++i)
	{
		for (int j = 0; j < neededMat.cols; ++j)
		{
			neededMat.at<Scalar>(j, i) = getScalarForFirstType(values.at<int>(i, j));
		}
	}
	return neededMat.clone();
}

Mat& ValuesBuilder::getSecondScalarMatType(const Mat& values)
{
	return Mat();
}

Scalar ValuesBuilder::getScalarForFirstType(int value)
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
	//std::cout << "red: "<<red<<" green: "<<green<<" blue: "<<blue<<" value: "<<value<<std::endl;
	//int k(0);
	//std::cin >> k;
	//return Scalar(0, 255, 255);
	return Scalar(blue, green, red);
}
