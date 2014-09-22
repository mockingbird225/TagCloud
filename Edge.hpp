#ifndef EDGE_H
#define EDGE_H
#include<iostream>
#include "Node.hpp"
using namespace std;

class Edge {
	Node* v1;
	Node* v2;
	double weight;
	public :
	Edge(Node* _v1, Node* _v2, double _weight);
	Node* getNode1() { return v1; }
	Node* getNode2() { return v2; }
	double getWeight() { return weight; }
};
#endif

