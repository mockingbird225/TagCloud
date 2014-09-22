#include "Graph.hpp"
#include "MinCutGraph.hpp"
Graph::Graph(bool _delPtr) {
	delPtr = _delPtr;
}

Graph* Graph::makeGraph(MinCutNode* node, bool _delPtr) {
	Graph* g = new Graph(_delPtr);
	vector<Node*> nodes = node->getNodes();
	map<Node*, bool> nodeMap;
	for(int i = 0; i < nodes.size(); i++) {
		nodeMap[nodes[i]] = true;
		g->addNodePtr(nodes[i]);
	}
	for(int i = 0; i < edges.size(); i++) {
		Node* n1 = edges[i]->getNode1();
		Node* n2 = edges[i]->getNode2();	
		if(nodeMap.find(n1) != nodeMap.end() && nodeMap.find(n2) != nodeMap.end()) {
			g->addEdgePtr(edges[i]);
		}
	}
	return g;
}

Graph::~Graph() {
	if(delPtr == true) {
		for(int i = 0; i < vertices.size(); i++) {
			delete(vertices[i]);
		}
		for(int i = 0; i < edges.size(); i++) {
			delete(edges[i]);
		}
	}
}

void Graph::addNodePtrs(vector<Node*>& nodes) {
	for(int i = 0; i < nodes.size(); i++) {
		vertices.push_back(nodes[i]);
	}
}
vector<Node*>& Graph::getNodes() {
	return vertices;
}
vector<Edge*>& Graph::getEdges() {
	return edges;
}
void Graph::printGraph() {
	queue<Node*> q;
	for(int i=0; i<vertices.size(); i++) {
		vertices[i]->setV(false);	
	}	
	q.push(vertices[0]);
	vertices[0]->setV(true);
	while(!q.empty()) {
		Node* curr = q.front();
		q.pop();
		//cout << "Node: " << curr->getName() << " No of neighbors: " << curr->getNeiSize() << endl;	
		for(int j = 0; j < curr->getNeiSize(); j++) {
			Node* nei = curr->getNei(j);
			if(!nei->getV()) {
				//cout << "Neighbor: " << nei->getName() <<" Edge weight: " << curr->getEdgeWeight(j) << endl;
				q.push(nei);
				nei->setV(true);
			}
		}
	}
}
void Graph::addNodePtr(Node* n) {
	vertices.push_back(n);
}

void Graph::addEdgePtr(Edge* e) {
	edges.push_back(e);
}
void Graph::findMinCut(vector<Graph*>& partitions) {
	if(vertices.size() == 2) {
		Graph* g = new Graph(false);
		g->addNodePtr(vertices[0]);
		partitions.push_back(g);
		g = new Graph(false);
		g->addNodePtr(vertices[1]);
		partitions.push_back(g);
		return;
	}
	MinCutGraph mcg(this);	
	mcg.print();
	mcg.findMinCut();
	partitions.push_back(makeGraph(mcg.getCut1(), false));
	partitions.push_back(makeGraph(mcg.getCut2(), false));
}

void Graph::partition(double xLeft, double yLeft, double length, double breadth, Partition* p) {
	//cout << "UUUU Number of vertices: " << vertices.size() << endl;
	if(vertices.size() == 1) {
		p->addRect(vertices[0]->getName(), xLeft, yLeft, length, breadth, vertices[0]->getFreq());
		return;	
	}
	vector<Graph*> partitions;
	findMinCut(partitions);
	if(partitions.size() != 2) {
		return;
	} 
	double sumWts1 = 0;
	double sumWts2 = 0;	
	vector<Node*> nodes = partitions[0]->getNodes();
	for(int i = 0; i < nodes.size(); i++) {
		sumWts1 += nodes[i]->getFreq();  		
	}
	nodes = partitions[1]->getNodes();
	for(int i = 0; i < nodes.size(); i++) {
		sumWts2 += nodes[i]->getFreq();  		
	}
	double tot = sumWts1+sumWts2;
	sumWts1 = sumWts1/tot;
	sumWts2 = 1-sumWts1;
	if(length >= breadth) {
		double l = length*sumWts1;
		partitions[0]->partition(xLeft, yLeft, l, breadth, p);
		partitions[1]->partition(l+xLeft, yLeft, length*sumWts2, breadth, p);
	} else {
		double b = breadth*sumWts1;
		partitions[0]->partition(xLeft, yLeft, length, b, p);
		partitions[1]->partition(xLeft, b+yLeft, length, b*sumWts2, p);
	}	
}

void Graph::setFreqs(const map<string, double>& _freqMap) {
	// _freqMap[string] = freq;
	map<string, double>::const_iterator freqIt;
	for(freqIt = _freqMap.begin(); freqIt != _freqMap.end(); freqIt++) {
		vertices.push_back(new Node(freqIt->first, freqIt->second*((freqIt->first).length())));
		strNodeMap[freqIt->first] = vertices.back();	
	}
}

vector<string> Graph::tokenize(string line, char delim) {
        stringstream ss(line);
        string s;
        vector<string> tokens;
        while( getline(ss, s, delim)) {
                tokens.push_back(s);
        }
        return tokens;
}

bool Graph::setWeights(const map<string, double>& _wtMap, const map<string, double>& _freqMap) {
	// _wtMap[string1:string2] = weight;
	map<string, double>::const_iterator wtIt;
	for(wtIt = _wtMap.begin(); wtIt != _wtMap.end(); wtIt++) {
		// Splitting string in weightmap into string1 and string2
		vector<string> str = tokenize(wtIt->first, ':');
		map<string, double>::const_iterator fIt;
		fIt = _freqMap.find(str[0]);
		double f0 = fIt->second;
		fIt = _freqMap.find(str[1]);
		double f1 = fIt->second;
		edges.push_back(new Edge(strNodeMap[str[0]], strNodeMap[str[1]], wtIt->second));
		// Adding neighbor to string1 and string2
		if(strNodeMap.find(str[0]) == strNodeMap.end() || strNodeMap.find(str[1]) == strNodeMap.end()) {
			//One or both of the nodes was not found in the map
			return false;			
		}
		strNodeMap[str[0]]->addNeighbor(strNodeMap[str[1]]);
		strNodeMap[str[0]]->addEdgeWeights(wtIt->second);
		strNodeMap[str[1]]->addNeighbor(strNodeMap[str[0]]);
		strNodeMap[str[1]]->addEdgeWeights(wtIt->second);
	}
	return true;
}

bool nodeSort(Node* a, Node* b) {
	string aStr = a->getName();
	string bStr = b->getName();
	double aFreq = a->getFreq();
	double bFreq = b->getFreq();
	return ( (aFreq/aStr.length()) > (bFreq/bStr.length()));
}
bool edgeSort(Edge* a, Edge* b) {
	return (a->getWeight() > b->getWeight()); 
}
void Graph::sortVertices() {
	sort(vertices.begin(), vertices.end(), nodeSort);
}
void Graph::sortEdges() {
	sort(edges.begin(), edges.end(), edgeSort);
}

void Graph::setAllVisitedFalse() {
	for(int i=0; i<vertices.size(); i++) {
                vertices[i]->setV(false);       
        }
}

void Graph::bfs(QuadTree* q) {
	Node* first = vertices[0];
	Word* word = new Word(x, y, height, width, getFreq(), getName());		
	plotInSpace(word);
	queue<Node*> bfsQueue;
	queue.push(first);
	while(!bfsQueue.empty()) {
		Node* top = bfsQueue.front();
		queue.pop();
		vector<Node*> neighbors = top.getNeighbors();
		for(int i = 0; i < neighbors.size(); i++) {
			neighbors[i]->setV(false);	
		}
		for(int i = 0; i < neighbors.size(); i++) {
			if(neighbors[i]->getV() == false) {
				bfsQueue.push(neighbors[i]);
				neighbors[i]->setV(true);
			}
		}
		Word* word = new Word(x, y, height, width, getFreq(), getName());		
		q->plotInSpace(word);
	}
}

Graph* Graph::pruneGraph(int k) {
	//sort the vertices in descending order of frequencies
	sortVertices();
	for(int i = 0; i < k; i++) {
		//cout << "Name: " << vertices[i]->getName() << " Freq: " << vertices[i]->getFreq() << endl;
	}
	Graph* prunedG = new Graph(true);
	for(int i = 0; i < k; i++) {
		prunedG->vertices.push_back(new Node(vertices[i]->getName(), vertices[i]->getFreq()));
		prunedG->strNodeMap[vertices[i]->getName()] = prunedG->vertices.back();
	}
	shPath sP;
	for(int i = 0; i < k-1; i++) {
		for( int j = i+1; j < k ; j++) {
			setAllVisitedFalse();
			double sp = sP.findShPath(vertices[i], vertices[j]);
			//cout << "Dist " <<  vertices[i]->getName() << " " << vertices[j]->getName() << " " << sp << endl;
			prunedG->edges.push_back(new Edge(prunedG->strNodeMap[vertices[i]->getName()], prunedG->strNodeMap[vertices[j]->getName()], sp));
			if(sp != numeric_limits<double>::max()) {
				prunedG->strNodeMap[vertices[i]->getName()]->addNeighbor(prunedG->strNodeMap[vertices[j]->getName()]);
				prunedG->strNodeMap[vertices[i]->getName()]->addEdgeWeights(sp);
				prunedG->strNodeMap[vertices[j]->getName()]->addNeighbor(prunedG->strNodeMap[vertices[i]->getName()]);
				prunedG->strNodeMap[vertices[j]->getName()]->addEdgeWeights(sp);
			}
		}
	}	
	return prunedG;
}
