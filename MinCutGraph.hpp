#ifndef MINCUTGRAPH_H
#define MINCUTGRAPH_H
#include "MinCutNode.hpp"
#include "Node.hpp"
#include "Edge.hpp"
using namespace std;
class Graph;
class MinCutEdge;
class MinCutGraph {
	vector<MinCutNode*> nodes;
	vector<MinCutEdge*> edges;
	public :
	MinCutGraph(Graph* g);
	void findMinCut();
	void print();
	void combineNodes(MinCutNode* n1, MinCutNode* n2);
	MinCutNode* getCut1() { return nodes[0]; }	
	MinCutNode* getCut2() { return nodes[1]; }
};

#endif
