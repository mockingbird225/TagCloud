#include "Rectangle.hpp"
#include<string>
Rectangle::Rectangle(double _xLeft, double _yLeft, double _length, double _breadth, string _word, double _frequency) {
		xLeft = _xLeft;
		yLeft = _yLeft;
		length = _length;
		breadth = _breadth;
		word = _word;
		frequency = _frequency;
}

void Rectangle::print() {
	cout << "XLeft: " << xLeft << " YLeft: " << yLeft << " Length: " << length << " Breadth: " << breadth << " Frequency: " << frequency/word.length() << " Word: " << word << endl;
}
