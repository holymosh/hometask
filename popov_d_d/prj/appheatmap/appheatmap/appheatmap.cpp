#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "valuesBuilder.h"

using namespace std;
using namespace cv;
int main()
{
	int width(400);
	Mat inputMat(20, 20, DataType<int>::type);
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			if (i%2)
			{
				inputMat.at<int>(i, j) = -j;
			}
			else
			{
				inputMat.at<int>(i, j) = j;
			}
		}
	}
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			cout << inputMat.at<int>(i, j)<< " ";
		}
		cout << endl;

	}
	
	ValuesBuilder builder(maptypes::first);
	Mat_<Scalar> matfrombuilder = builder.getValuesMatrix(inputMat, maptypes::first);
	
	Mat img(Mat::zeros(width, width, CV_8UC4));
	int w(width/20);
	int h(w);
	for (int i(0) ; i < 400 ; i+=w )
	{
		for (int j = 0; j < 400; j+=h)
		{
			//Scalar_<double> scal = matScalar.at<Scalar>(i, j);
			rectangle(img, Rect(i, j, w, h),matfrombuilder.at<Scalar>(2,9), CV_FILLED);
		}
	}
	imshow("heatmap", img);
	waitKey(0);
    return 0;
}

