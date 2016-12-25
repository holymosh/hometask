#include "paletteManager.h"
#include <fstream>
#include <iostream>

using namespace std;
PaletteManager::~PaletteManager()
{
}

void PaletteManager::openPaletteFile()
{
	ofstream ofstream;
	ofstream.open("palette.txt");
	ofstream.clear();
	for (int i = 0; i < rgb_vector_.size()-1; ++i)
	{
		ofstream << "value: ";
		ofstream << rgb_vector_.at(i).value+1<<" ";
		ofstream << "red: ";
		ofstream << rgb_vector_.at(i).red+1 << " ";
		ofstream << "green: ";
		ofstream << rgb_vector_.at(i).green+1 << " ";
		ofstream << "blue: ";
		ofstream << rgb_vector_.at(i).blue+1 << " "<<endl;
	}
	
}

void PaletteManager::readPaletteFile(char*  path)
{
	ifstream ifstream;
	ifstream.open(path);
	double red(0.0);
	double green(0.0);
	double blue(0.0);
	int value(0);
	char valuestr[7];
	char redstr[5];
	char bluestr[6];
	char greenstr[7];

	while (!ifstream.eof())
	{
		ifstream >> valuestr;
		ifstream >> value;
		ifstream >> redstr;
		ifstream >> red;
		ifstream >> greenstr;
		ifstream >> green;
		ifstream >> bluestr;
		ifstream >> blue;
		rgbValue rgb_value(red,green,blue ,value);
		rgb_vector_.push_back(rgb_value);

	}
	for (int i = 0; i < rgb_vector_.size()-1; ++i)
	{
		std::cout << rgb_vector_.at(i).value << " " << rgb_vector_.at(i).red << " " << rgb_vector_.at(i).green << " " << rgb_vector_.at(i).blue << " " << endl;
	}
}
