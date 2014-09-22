#include "MinCutGraph.hpp"
#include "Graph.hpp"

MinCutGraph::MinCutGraph(Graph* g) {
	vector<Node*>& graphNodes = g->getNodes();
	vector<Edge*>& graphEdges = g->getEdges();
	map<Node*, MinCutNode*> minCutNodeMap;
	for(int i = 0; i < graphNodes.size(); i++) {
		MinCutNode* temp = new MinCutNode(graphNodes[i]);
		nodes.push_back(temp);
		//cout << "GraphNode : " << graphNodes[i]  << " " << temp << endl;
		minCutNodeMap[graphNodes[i]] = temp;
	}			
	for(int i = 0; i < graphEdges.size(); i++) {
		Node* n1 = graphEdges[i]->getNode1();
		Node* n2 = graphEdges[i]->getNode2();
		double _weight = graphEdges[i]->getWeight();
		//cout << " n1: " << n1 << " n2: " << n2 << " Edge: " << minCutNodeMap[n1] << " " << minCutNodeMap[n2] << endl;
		edges.push_back(new MinCutEdge(minCutNodeMap[n1], minCutNodeMap[n2], _weight));
	}
}

void MinCutGraph::print() {
	//cout << "Nodes size: " << nodes.size() << endl;
	//cout << "Edges size: " << edges.size() << endl;
	for(int i = 0; i < edges.size(); i++) {
		//cout << "Edge" << endl;
		(edges[i]->getNode1())->print();
		(edges[i]->getNode2())->print();
		//cout << "Weight: " << edges[i]->getWeight() << endl;
	}	
}
void MinCutGraph::combineNodes(MinCutNode* n1, MinCutNode* n2) {
	//cout << " Combine Nodes" << endl;
	n1->print();
	n2->print();
	map<MinCutNode*, double> smallestWt;
	n1->combineNode(n2);
	// Erasing "n2" from the vector	
	for(vector<MinCutNode*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		if(*it == n2) {
			nodes.erase(it);
			break;
		}	
	}
	//cout << "Nodes print" << endl;
	for(int i = 0; i < nodes.size(); i++) {
		nodes[i]->print();	
	}
	
	// Erasing the edges of "n2"
	for(vector<MinCutEdge*>::iterator it = edges.begin(); it != edges.end(); it++) {
		MinCutNode* edgeN1 = (*it)->getNode1();
		MinCutNode* edgeN2 = (*it)->getNode2();
		double w = (*it)->getWeight();
		if(edgeN1 == n2) {
			if(smallestWt.find(edgeN2) == smallestWt.end() || smallestWt[edgeN2] > w) {
				smallestWt[edgeN2] = w;
			} 
			edges.erase(it); 
			it--;
			continue;
		}
		if(edgeN2 == n2) {
			if(smallestWt.find(edgeN1) == smallestWt.end() || smallestWt[edgeN1] > w) {
				smallestWt[edgeN1] = w;
			} 
			edges.erase(it);
			it--; 
			continue;

		}
	}
	for(vector<MinCutEdge*>::iterator it = edges.begin(); it != edges.end(); it++) {
		MinCutNode* edgeN1 = (*it)->getNode1();
		MinCutNode* edgeN2 = (*it)->getNode2();
		double w = (*it)->getWeight();
		if(edgeN1 == n1) {
			if(smallestWt.find(edgeN2) != smallestWt.end() && smallestWt[edgeN2] < w) {
				(*it)->changeWeight(smallestWt[edgeN2]);
			} 
			continue;
		}
		if(edgeN2 == n1) {
			if(smallestWt.find(edgeN1) != smallestWt.end() && smallestWt[edgeN1] < w) {
				(*it)->changeWeight(smallestWt[edgeN1]);
			} 
			continue;

		}
	}
	//cout << "Edges print" << endl;
	for(int i = 0; i < edges.size(); i++) {
		edges[i]->print();	
	}
}
void MinCutGraph::findMinCut() {
	while(nodes.size() > 2) {
		MinCutEdge* bestEdge = edges[0];
		edges.erase(edges.begin());
		combineNodes(bestEdge->getNode1(), bestEdge->getNode2());
	}
	
}

