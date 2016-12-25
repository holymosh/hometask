#include "heatmapBuilder.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

Mat HeatMapBuilder::createHeatMap(Mat scalars)
{
	int width(scalars.rows);
	int valueWidth(1);
	int valueHeight(1);
	int height(scalars.cols);
	Mat img(Mat::zeros(height, width, CV_8UC4));
	for (int i = 0; i < scalars.rows; ++i)
	{
		for (int j = 0; j < scalars.cols; ++j)
		{
			rectangle(img, Rect(i*valueWidth, j*valueHeight, valueWidth, valueHeight), scalars.at<Scalar>(i, j),CV_FILLED);
		}
	}
	return img;

}
