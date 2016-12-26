#include "opencv2/highgui/highgui.hpp"
#include "valuesBuilder.h"
#include "heatmapBuilder.h"
#include <ctime>

using namespace std;
using namespace cv;
void buildCustom();
void buildDefault();
void cExample();
int main()
{
	buildCustom();
	buildDefault();
	return 0;
}

void buildCustom()
{
	Mat_<int> inputMat(300, 300, DataType<int>::type);
	srand(time(0));
	int one(1);
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			inputMat.at<int>(i, j) = abs(j - i)/2;
		}
		one = -one;
	}
	ValuesBuilder builder;
	HeatMapBuilder heat_map_builder;
	char path[]{ "palette.txt" };
	//builder.createPaletteForValues(path, inputMat);
	Mat scalars = builder.getCustomColorsMat(path, inputMat);
	Mat heatMap = heat_map_builder.createHeatMap(scalars);
	imshow("heatMap", heatMap);
	waitKey(0);
}
void buildDefault()
{
	Mat_<int> inputMat(500, 500, DataType<int>::type);
	srand(time(0));
	int one(1);
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			inputMat.at<int>(i, j) = j - i;
		}
		one = -one;
	}
	ValuesBuilder builder;
	Mat_<Scalar> needed_mat = builder.getDefaultColorsMat(inputMat);
	HeatMapBuilder heat_map_builder;
	Mat heatMap = heat_map_builder.createHeatMap(needed_mat);
	imshow("heatMap", heatMap);
	waitKey(0);
}

void cExample()
{
	Mat inputMat(500, 500, DataType<int>::type);
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			inputMat.at<int>(i, j) = (j-i);
		}
	}
		CvMat mat(inputMat);
		CvMat newMat = create_Cvmat(&mat);
		CvMat* nm = &newMat;
		Mat img = cvarrToMat(nm);
		imshow("c-func hmp", img); 
		waitKey(0);
	
}
