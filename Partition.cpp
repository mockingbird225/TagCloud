#include "Partition.hpp"

void Partition::addRect(string word, double xLeft, double yLeft, double l, double b, double frequency) {
	rectPartitions.push_back(new Rectangle(xLeft, yLeft, l, b, word, frequency));
}

void Partition::print() {
	for(int i = 0; i < rectPartitions.size(); i++) {
		rectPartitions[i]->print();
	}
}
