#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<algorithm>
#include "Node.hpp"
#include "Edge.hpp"
#include "Rectangle.hpp"
#include "Utility.hpp"
#include "MinCutNode.hpp"
#include "MinCutGraph.hpp"
#include "MinCutEdge.hpp"
#include "shPath.hpp"
#include "QuadTree.hpp"
#include "Word.hpp"
#include "Partition.hpp"
using namespace std;
class MinCutGraph;
class Graph {
	vector<Node*> vertices;
	vector<Edge*> edges;
	map<string, Node*> strNodeMap;
	vector<string> tokenize(string str, char delim);
	vector<Rectangle*> rectangles;
	bool delPtr;
	public:
	Graph(){ };
	Graph(bool _delPtr);
	Graph* makeGraph(MinCutNode* node, bool _delPtr);
	void printGraph();
	void setFreqs(const map<string, double>& _freqMap);
	bool setWeights(const map<string, double>& _wtMap, const map<string, double>& _freqMap);
	void setAllVisitedFalse();
	void addNodePtr(Node* n);
	void addEdgePtr(Edge* e);
	void findMinCut(vector<Graph*>& partitions);
	vector<Node*>& getNodes();
	vector<Edge*>& getEdges();
	void addNodePtrs(vector<Node*>& nodes);
	void partition(double _xLeft, double _yLeft, double _length, double _breadth, Partition* p);
	Graph* pruneGraph(int k);
	void sortVertices();
	void sortEdges();
	~Graph();
};
#endif
