#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<iostream>
using namespace std;

class Rectangle {
	double xLeft; // Top left
	double yLeft;
	double length; // Bottom Right
	double breadth;
	string word;
	double frequency;
	public :
	Rectangle(double _xLeft, double _yLeft, double _length, double _breadth, string _word, double _frequency);	
	double getXLeft() { return xLeft; }
	double getYLeft() { return yLeft; }
	double getLength() { return length; }
	double getBreadth() { return breadth; }
	string getWord() { return word; }
	double getFrequency() { return frequency; }
	void print();
};
#endif
