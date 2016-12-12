// appheatmap.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;
int main()
{
	int width(400);
	
	Mat img(Mat::zeros(width, width, CV_8UC4));
	Mat mt(5,4,DataType<int>::type);
	for (ptrdiff_t i(0); i < mt.rows; ++i)
	{
		for (ptrdiff_t j = 0; j < mt.cols; ++j)
		{
			mt.at<int>(i, j) = j+100;
		}
	}
	for (ptrdiff_t i(0); i < mt.rows; ++i)
	{
		for (ptrdiff_t j = 0; j < mt.cols; ++j)
		{
			cout << mt.at<int>(i, j) << " ";
		}
		cout << '\n';
	}
	int w(width/400);
	int h(w);
	
	for (int i(0); i < 400; i+=w)
	{
		for (int j = 0; j < 400; j+=h)
		{
			rectangle(img, Rect(i, j, w, h), Scalar(0,i/1.3+30,j/1.3+30) , CV_FILLED);
		}
	}
	imshow("heatmap", img);
	waitKey(0);
    return 0;
}

