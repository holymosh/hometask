#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "valuesBuilder.h"
#include "heatmapBuilder.h"
#include <ctime>

using namespace std;
using namespace cv;
int main()
{
	Mat inputMat(500, 500, DataType<int>::type);
	srand(time(0));
	int one(1);
	for (int i = 0,i1(0); i < inputMat.rows; ++i,i1++)
	{
		for (int j = 0,j1(20); j < inputMat.cols; j+=2,j1--)
		{
			inputMat.at<int>(i, j) = i1;
			if (j1==-20)
			{
				j1 = 20;
			}
			if (i1==20)
			{
				i1 = -20;
			}
			one = -one;
		}
		for (int j = 1, j1(20); j < inputMat.cols; j += 2, j1--)
		{
			inputMat.at<int>(i, j) = j1;
			if (j1 == -20)
			{
				j1 = 20;
			}
			if (i1 == 20)
			{
				i1 = -20;
			}
			one = -one;
		}
		one = -one;
	}
	
	ValuesBuilder builder;
	Mat_<Scalar> needed_mat = builder.getScalarMat(inputMat);
	HeatMapBuilder heat_map_builder;
	Mat heatMap = heat_map_builder.createHeatMap(needed_mat);
	imshow("heatMap", heatMap);
	waitKey(0);
    return 0;
}

