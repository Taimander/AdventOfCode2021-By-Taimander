#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input8.txt");
    string line;

    vector<string> values;
    int ptOneCount = 0;
    while(getline(file,line)) {
        int sepindex = line.find(" | ");
        string inputs = line.substr(0,sepindex);
        string outputs = line.substr(sepindex+3,line.size()-1);
        stringstream inputstream(inputs);
        stringstream outputstream(outputs);
        string val;
        for(int i = 0; i < 10; i++) {
            getline(inputstream,val,' ');
            values.push_back(val);
        }
        for(int i = 0; i < 4; i++) {
            getline(outputstream,val,' ');
            switch(val.size()) {
                case 2: 
                case 4:
                case 3:
                case 7:
                    ptOneCount++;
                    break;
                default:
                    break;

            }
        }
    }
    
    cout << "Part One: " << ptOneCount << endl;

    return 0;
}