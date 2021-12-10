#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input6.txt");
    string line;

    int daysToSimulate = 256;
    int partOneDay = 80;

    long long fishCounts[9] = {};
    getline(file,line);

    stringstream ss(line);
    long long v;
    while(!ss.eof()) {
        ss >> v;
        fishCounts[v]++;
        if(ss.peek() == ',') {
            ss.ignore();
        }
    }
    long long fishCountsTemp[9] = {};
    long long totalFish = 0;
    for(int day = 0; day < daysToSimulate; day++) {
        fishCountsTemp[8] = 0;
        for(int i = 1; i < 9; i++) {
            fishCountsTemp[i-1] = fishCounts[i]; 
        }
        fishCountsTemp[6] += fishCounts[0];
        fishCountsTemp[8] += fishCounts[0];
        for(int i = 0; i < 9; i++) {
            fishCounts[i] = fishCountsTemp[i];
        }
        if(day == partOneDay-1) {
            totalFish = 0;
            for(long long j : fishCounts) {
                totalFish += j;
            }
            cout << "Part One: " << totalFish << endl;
        }
    }
    totalFish = 0;
    for(long long j : fishCounts) {
        totalFish += j;
    }
    cout << "Part Two: " << totalFish << endl;

    return 0;
}