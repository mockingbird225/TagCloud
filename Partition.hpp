#ifndef PARTITION_H
#define PARTITION_H
#include<vector>
#include "Rectangle.hpp"
class Partition {
	vector<Rectangle*> rectPartitions;
	public:
	void addRect(string word, double xLeft, double yLeft, double l, double b, double frequency);	
	void print();
};
#endif
