#ifndef MINCUTNODE_H
#define MINCUTNODE_H
#include "Node.hpp"
using namespace std;
class MinCutNode {
	vector<Node*> nodes;
	public :
	MinCutNode(Node* n);	
	~MinCutNode();	
	void combineNode(MinCutNode* node);
	vector<Node*>& getNodes() { return nodes; }
	void print();
};
#endif
