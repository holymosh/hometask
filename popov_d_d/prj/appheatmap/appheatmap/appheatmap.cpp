#include "opencv2/highgui/highgui.hpp"
#include "valuesBuilder.h"
#include "heatmapBuilder.h"
#include <ctime>

using namespace std;
using namespace cv;
int main()
{
	Mat_<int> inputMat(500, 500, DataType<int>::type);
	srand(time(0));
	int one(1);
	for (int i = 0; i < inputMat.rows; ++i)
	{
		for (int j = 0; j < inputMat.cols; ++j)
		{
			inputMat.at<int>(i, j) = j;
		}
		one = -one;
		
	}
	ValuesBuilder builder;
	//Mat_<Scalar> needed_mat = builder.getDefaultColorsMat(inputMat);
	HeatMapBuilder heat_map_builder;
	//Mat heatMap = heat_map_builder.createHeatMap(needed_mat);
	//imshow("heatMap", heatMap);
	//waitKey(0);
	char path[]{"palette.txt"};
	//builder.createPaletteForValues(path, inputMat);
	Mat scalars = builder.getCustomColorsMat(path, inputMat);
	Mat heatMap = heat_map_builder.createHeatMap(scalars);
	imshow("heatMap", heatMap);
	waitKey(0);
    return 0;
}

