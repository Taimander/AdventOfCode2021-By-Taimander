#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int abs(int v) {
    if(v < 0) return -v;
    return v;
}

int fuelCost(int moves) {
    return (moves*(moves+1))/2; 
}

int main() {
    ifstream file("input7.txt");
    string line;

    int minPosition = 9999;
    int maxPosition = 0;

    getline(file,line);
    stringstream ss(line);
    vector<int> positions;
    int v;
    while(!ss.eof()) {
        ss >> v;
        if(v < minPosition) {
            minPosition = v;
        }
        if(v > maxPosition) {
            maxPosition = v;
        }
        positions.push_back(v);
        if(ss.peek() == ',') {
            ss.ignore();
        }
    }
    int minCost = 99999999;
    int minCostPt2 = 99999999;
    for(int i = minPosition; i <= maxPosition; i++) {
        int cost = 0;
        int cost2 = 0;
        for(int j = 0; j < positions.size(); j++) {
            cost += abs(positions[j]-i);
            cost2 += fuelCost(abs(positions[j]-i));
        }
        if(cost < minCost) {
            minCost = cost;
        }
        if(cost2 < minCostPt2) {
            minCostPt2 = cost2;
        }
    }

    cout << "Part One: " << minCost << endl;
    cout << "Part Two: " << minCostPt2 << endl;

    return 0;
}
