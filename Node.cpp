#include "Node.hpp"

Node::Node(string _name, double _freq) {
	name = _name;	
	freq = _freq;
}
/*void Node::copyNode(Node* n) {
	name = n->getName();
	freq = n->getFreq();
	neighbors = n->getNeighbors();
	vector<Node*> nei = n->getNeighbors();
	for(int i = 0; i < nei.size(); i++) {
		neighbors.push_back(nei[i]);
	}
	edgeWeights = n->getEdgeWeights();
}*/
void Node::setV(bool set) {
	visited = set;
}

bool Node::getV() {
	return visited;
}

string Node::getName() {
	return name;
}

double Node::getFreq() {
	return freq;
}

int Node::getNeiSize() {
	return neighbors.size();
}

vector<Node*>& Node::getNeighbors() {
	return neighbors;
}

vector<double>& Node::getEdgeWeights() {
	return edgeWeights;
}

Node* Node::getNei(int index) {
	return neighbors[index];
}

double Node::getEdgeWeight(int index) {
	return edgeWeights[index];
}


