#ifndef COLORMANAGER
#define COLORMANAGER
#include <vector>
#include <opencv2/core/mat.hpp>

struct rgbValue
{
	double red{0.0};
	double green{0.0};
	double blue{0.0};
	int value{0};
	rgbValue() = default;
	rgbValue(double red, double green, double blue, int value)
		: red(red),
		  green(green),
		  blue(blue),
		  value(value)
	{}

};

class PaletteManager
{
public:

	PaletteManager()=default;
	~PaletteManager();
	void savePalette(char* path);
	void readPaletteFile(char* path);
	void addColor(rgbValue value);
	cv::Scalar getColorForValue(int value);

private:
	std::vector<rgbValue> rgb_vector_{};
	bool containsColor(rgbValue value);
};


#endif
