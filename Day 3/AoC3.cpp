#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("input3.txt");
    vector<string> lines;
    string line;

    const int width = 12;

    int zeros_occurrences[width] = {};
    int ones_occurrences[width] = {};

    while(getline(file, line)) {
        lines.push_back(line);
        for(int i = 0; i < width; i++) {
            switch(line[i]) {
                case '0':
                    zeros_occurrences[i]++;
                    break;
                case '1':
                    ones_occurrences[i]++;
                    break;
                default:
                    break;
            }
        }
    }
    int gamma = 0;
    int delta = 0;

    for(int i = 0; i < width; i++) {
        if(zeros_occurrences[i] > ones_occurrences[i]) {
            delta |= 1 << (width - i - 1);
        }else{
            gamma |= 1 << (width - i - 1);
        }
    }
    /*
    vector<string> oxygen_vector{lines.begin(),lines.end()};
    int ones = 0;
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < oxygen_vector.size(); j++) {
            if((oxygen_vector[j])[i] == '1') {
                ones++;
            }
        }
        char target = '0'+(ones > (oxygen_vector.size()-ones));
        vector<string> newvector;
        for(int k = oxygen_vector.size(); k >= 0; k--) {
            if((oxygen_vector[k])[i] == target) {
                newvector.push_back(oxygen_vector[k]);
            }
        }
        oxygen_vector = newvector;
    }
    cout << oxygen_vector[0] << endl;
    */

    cout << "Part one: " << (delta * gamma) << endl;
    cout << "Part two: To be implemented..." << endl;
    return 0;
}