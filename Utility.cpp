#include "Utility.hpp"

double strToDouble(string str) {
	stringstream ss(str);
	double d = 0.0;
	ss >> d;
	return d;
}

vector<string> tokenize(string line, char delim) {
	stringstream ss(line);
        string s;
        vector<string> tokens;
        while( getline(ss, s, delim)) {
                tokens.push_back(s);
        }
        return tokens;
}
