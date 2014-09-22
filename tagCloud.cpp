#include "Graph.hpp"
#include "Utility.hpp"
#include<fstream>
void readFreqFile(string freqFile, map<string, double>& freqMap) {
	ifstream freqFS(freqFile.c_str());
	string line;
	vector<string> str;
	if(freqFS.is_open()) {
		while(getline(freqFS, line)) {
			str = tokenize(line, ' ');
			if( freqMap.find(str[0]) == freqMap.end()) {
				freqMap[str[0]] = strToDouble(str[1]);
			}	
		}
	}
}

void readwtFile(string wtFile, map<string, double>& wtMap) {
	ifstream wtFS(wtFile.c_str());
	string line;
	vector<string> str;
	if(wtFS.is_open()) {
		while(getline(wtFS, line)) {
			str = tokenize(line, ' ');
			if( wtMap.find(str[0]) == wtMap.end()) {
				wtMap[str[0]] = strToDouble(str[1]);
			}	
		}
	}
}

int main(int argc, char* argv[]) {
	if( argc != 6) {
		cerr << "Usage: " << argv[0] << " <freqFile> <weightFile> <k> <length> <breadth>" << endl;
		exit(1);
	}
	Graph g;
	QuadTree* q = new QuadTree(0, 0, height, width, )
	map<string, double> freqMap;
	map<string, double> wtMap;
	readFreqFile(argv[1], freqMap);
	readwtFile(argv[2], wtMap);
	int k = atoi(argv[3]);
	int length = atoi(argv[4]);
	int breadth = atoi(argv[5]);
	g.setFreqs(freqMap);
	g.setWeights(wtMap, freqMap);
	//g.printGraph();	
	Graph* prunedGraph = g.pruneGraph(k);
	cout << "Pruned Graph "  << k << endl;
	prunedGraph->printGraph();
	prunedGraph->bfs();
	//Partition p;
	//prunedGraph->partition(0, 0, length, breadth, &p);  // Top Left (0,0);Bottom Right (l,b)
	//p.print();
}
