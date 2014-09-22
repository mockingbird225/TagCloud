#include "shPath.hpp"

double shPath::findShPath(Node* a, Node* b) {
        priority_queue<qEle*, vector<qEle*>, compareDist > q;
	qEle* dest = NULL;
	map<Node*, qEle*> nodeToQ;
	qEle* temp;
        temp = new qEle(a, 0.0);
        q.push(temp);
        nodeToQ[a] = temp;
	a->setV(true);
        while(!q.empty()) {
                qEle* curr = q.top();
                q.pop();
		//cout << "Queue " << curr->getNode()->getName() << endl;
                vector<Node*> n = (curr->getNode())->getNeighbors(); // For Neighbors        
                for(int j = 0; j < n.size(); j++) {
			double newDist = curr->getDist() + (curr->getNode())->getEdgeWeight(j); // Find path distance upto here  
                        if(n[j]->getV()) {
				// If node is already visited, compare with
				// adjacent distances
				temp = nodeToQ[n[j]];
				if( temp->getDist() > newDist) {
					temp->setDist(newDist);
				}	
                                continue;
                        }
			temp = new qEle(n[j], newDist);
			q.push(temp);
			nodeToQ[n[j]] = temp;
			n[j]->setV(true);
			if(n[j] == b) {
				dest = temp;
			}
                }
        }
	if(dest != NULL) {
		return dest->getDist();			
	} 
	return numeric_limits<double>::max();
}
