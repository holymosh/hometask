#include "valuesBuilder.h"
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;


ValuesBuilder::~ValuesBuilder()
{
}



Mat_<Scalar> ValuesBuilder::getScalarMat(Mat_<int>& values)
{
	values = makeValuesValidIfNeeded(values);
	/*for (int i = 0; i < values.rows; ++i)
	{
		for (int j = 0; j < values.cols; ++j)
		{
			std::cout << values.at<int>(i,j)<<" ";
		}
		std::cout << std::endl;
	}*/
	Mat_<Scalar> scalarMat(values.rows, values.cols, DataType<Scalar>::type);
	 scalarMat = createScalarMat(values);
	 return scalarMat;
}

Mat_<int>& ValuesBuilder::makeValuesValidIfNeeded(Mat_<int>& values)
{
	int min(values.at<int>(0,0));
	int max(min);
	for (int i(0); i < values.rows; ++i)
	{
		for (int j(0); j < values.cols; ++j)
		{
			int currentValue(values.at<int>(i, j));
			if (currentValue>max)
			{
				max = currentValue;;
			}
			if (currentValue<min)
			{
				min = currentValue;
			}
		}
	}
	std::cout << "min : "<<min<<" max : "<<max<<std::endl;
	if (min<-20 || max>20)
	{
		for (int i = 0; i < values.rows; ++i)
		{
			for (int j = 0; j < values.cols; ++j)
			{
				int currentValue(values.at<int>(i, j));
				double part =(double) (currentValue - min) / (max - min);
				int validValue(-20 + part * 40);
				values.at<int>(i, j) = validValue;
			}
		}
	}
	return values;
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
