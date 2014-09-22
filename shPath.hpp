#ifndef SHPATH_H
#define SHPATH_H
#include<map>
#include<limits>
#include<queue>
#include "Node.hpp"
class qEle {
	Node* node;
	double dist;
	public:
	qEle(Node *_node, double _dist) {
		node = _node;
		dist = _dist;
	}
	double getDist() {
		return dist;
	}
	void setDist(double newDist) {
		dist = newDist;
	}
	Node* getNode() {
		return node;
	}
};
class compareDist{
	public:
	bool operator() (qEle* q1, qEle* q2) {
		if( q2->getDist() < q1->getDist()) {
			return true;
		}
		return false;
	}	
};

class shPath {
	public :
	double findShPath(Node* a, Node* b);
};
#endif
