#ifndef VALUESBUILDER
#define VALUESBUILDER
#include <opencv2/core/mat.hpp>
#include <opencv2/core.hpp>
#include "paletteManager.h"
using namespace cv;
class ValuesBuilder
{
public:
	ValuesBuilder()= default;
	~ValuesBuilder();
	Mat getDefaultColorsMat(Mat& values);
	void createPaletteForValues(char* path, Mat& values);
	Mat getCustomColorsMat(char* path, Mat& values);
private:
	Mat_<Scalar> createScalarMat(Mat& values);
	Scalar createScalar(int value, int min, int max);
	PaletteManager palette_manager_{};
	rgbValue createRgbValueStruct(int value, int min, int max);

};
extern "C" CvMat create_Cvmat(CvMat* cv_mat);
#endif
