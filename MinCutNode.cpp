#include "MinCutNode.hpp"

MinCutNode::~MinCutNode() {
	
}
MinCutNode::MinCutNode(Node* n) {
//	cout << "Node name in new mcnode: " << n->getName() << endl;
	nodes.push_back(n);
}
void MinCutNode::combineNode(MinCutNode* otherNode) {
	vector<Node*>& otherNodes = otherNode->getNodes();
	for(int i = 0; i < otherNodes.size(); i++) {
		nodes.push_back(otherNodes[i]);
	}
}
void MinCutNode::print() {
//	cout << "Nodes size: " << nodes.size();
	for(int i = 0; i < nodes.size(); i++) {
//		cout << "Name: " << nodes[i]->getName() << " Freq : " << nodes[i]->getFreq() << " ";
	}
//	cout << endl;
}
