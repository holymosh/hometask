#include "valuesBuilder.h"
#include <opencv2/highgui.hpp>
#include <iostream>
#include "heatmapBuilder.h"

using namespace cv;


ValuesBuilder::~ValuesBuilder()
{
}


Mat ValuesBuilder::getScalarMat(Mat& values)
{
	//values = makeValuesValidIfNeeded(values);
	/*for (int i = 0; i < values.rows; ++i)
	{
		for (int j = 0; j < values.cols; ++j)
		{
			std::cout << values.at<int>(i,j)<<" ";
		}
		std::cout << std::endl;
	}*/
	Mat scalarMat(values.rows, values.cols, DataType<Scalar>::type);
	 scalarMat = createScalarMat(values);
	 return scalarMat;
}

Mat_<Scalar> ValuesBuilder::createScalarMat( Mat& values)
{
	int min(values.at<int>(0, 0));
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
	Mat_<Scalar> neededMat(values.rows, values.cols, DataType<Scalar>::type);
	for (int i = 0; i < neededMat.rows; ++i)
	{
		for (int j = 0; j < neededMat.cols; ++j)
		{
			neededMat.at<Scalar>(j, i) = createValuetest(values.at<int>(i, j),min,max);
		}
	}
	return neededMat;
}


Scalar ValuesBuilder::createValuetest(int value , int min , int max)
{
	double red(0);
	double green(0);
	double blue(0);
	double avgValue((max + min) / 2);
	if (value < avgValue)
	{
		blue += 25;
		for (int i(min); i <value; ++i)
		{
			blue += 255 / (avgValue - min);
		}
		return Scalar(blue, green, red);
	}
	
	if (value>avgValue &&  value< ((max+avgValue)/2) )
	{
		green = 255;
		blue = 0;
		for (int i = avgValue; i < value; ++i)
		{
			green -= 255 / ((max + avgValue));
		}
		return Scalar(blue, green, red);
	}
	if (value>avgValue &&  value> ((max + avgValue) / 2))
	{
		green = 255 - 2 * 18.214;
		red = 255;
		for (int i((max + avgValue) / 2); i < value; ++i)
		{
			green -= 255 / (max - value+1);
		}
		return Scalar(blue, green, red);
	}
	return Scalar(blue, green, red);

}

CvMat create_Cvmat(CvMat* cv_mat)
{
	try
	{
		Mat_<int> mat(cv_mat->rows, cv_mat->cols, DataType<int>::type);
		mat = cvarrToMat(cv_mat);
		ValuesBuilder builder;
		Mat_<Scalar> scalars = builder.getScalarMat(mat);
		HeatMapBuilder hmpbuilder;
		Mat heatmap = hmpbuilder.createHeatMap(scalars);
		CvMat result(heatmap);
		return result;

	}
	catch (Exception)
	{
		throw std::exception("exception");
	}
}
