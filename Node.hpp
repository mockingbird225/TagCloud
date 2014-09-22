#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
	int freq;
	string name;
	vector<Node*> neighbors;
	vector<double> edgeWeights;
	bool visited;
	public:
	Node(string _name, double _freq);
	Node(Node& n);
	void addNeighbor(Node* neighbor);
	void addEdgeWeights(double wt);
	void setV(bool set);
	bool getV();
	Node* getNei(int index);
	vector<Node*>& getNeighbors();
	vector<double>& getEdgeWeights();
	double getFreq();
	double getEdgeWeight(int index);
	string getName();
	int getNeiSize();
};

inline void Node::addNeighbor(Node* neighbor) {
	neighbors.push_back(neighbor);	
}

inline void Node::addEdgeWeights(double wt) {
	edgeWeights.push_back(wt);
}

#endif
