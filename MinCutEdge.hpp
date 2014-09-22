#ifndef MINCUTEDGE_H
#define MINCUTEDGE_H
#include "MinCutNode.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
using namespace std;
class MinCutEdge {
	double weight;
	MinCutNode* n1;
	MinCutNode* n2;
	public :
	MinCutEdge(MinCutNode* node1, MinCutNode* node2, double _weight);
	~MinCutEdge();
	MinCutNode* getNode1() { return n1; }
	MinCutNode* getNode2() { return n2; }
	void changeWeight(double _weight) { weight = _weight; }
	void print();
	double getWeight() { return weight; }
};

#endif
