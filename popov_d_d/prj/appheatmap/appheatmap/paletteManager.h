#ifndef COLORMANAGER
#define COLORMANAGER
#include <vector>

struct rgbValue
{
	double red;
	double green;
	double blue;
	int value;

	rgbValue(double red, double green, double blue, int value)
		: red(red),
		  green(green),
		  blue(blue),
		  value(value)
	{
	}
};

class PaletteManager
{
public:

	PaletteManager()=default;
	~PaletteManager();
	void savePalette(char* path);
	void readPaletteFile(char* path);
	void addColor(int value , double red, double green , double blue);

private:
	std::vector<rgbValue> rgb_vector_{};

};


#endif
