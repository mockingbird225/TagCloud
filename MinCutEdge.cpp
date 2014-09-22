#include "MinCutEdge.hpp"

MinCutEdge::~MinCutEdge() {
}

MinCutEdge::MinCutEdge(MinCutNode* node1, MinCutNode* node2, double _weight) {
	n1 = node1;
	n2 = node2;
	weight = _weight;
}
void MinCutEdge::print() {
//	cout << "Edge: " << endl;
	n1->print();
	n2->print();
//	cout << "Weight: " << weight << endl;
}
