#ifndef WORD_H
#define WORD_H
#include<iostream>
#include<string>
using namespace std;
class Word {
	double x;
	double y;
	double width;
	double height;
	double frequency;
	string word;
	public :
	Word(double _x, double _y, double _height, double _width, double _frequency, string _word);
	double getWordX() { return x; }
	double getWordY() { return y; }
	double getWordHeight() { return height; }
	double getWordWidth() { return width; }
	double getWordFrequency() { return frequency; }
	string getWord() { return word; }
};
#endif
