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
    
    vector<string> oxygen_vector{lines.begin(),lines.end()};
    vector<string> co2_vector{lines.begin(),lines.end()};
    vector<string> temp;
    for(int i = 0; oxygen_vector.size() > 1; i++) {
        temp.clear();
        int zeros = 0;
        int ones = 0;
        for(int j = 0; j < oxygen_vector.size(); j++) {
            if(oxygen_vector[j][i] == '0') {
                zeros++;
            }else {
                ones++;
            }
        }
        char most_common = '0';
        if(ones >= zeros) most_common = '1';
        for(int j = 0; j < oxygen_vector.size(); j++) {
            if(oxygen_vector[j][i] == most_common) {
                temp.push_back(oxygen_vector[j]);
            }
        }
        oxygen_vector = temp;
    }

    for(int i = 0; co2_vector.size() > 1; i++) {
        temp.clear();
        int zeros = 0;
        int ones = 0;
        for(int j = 0; j < co2_vector.size(); j++) {
            if(co2_vector[j][i] == '0') {
                zeros++;
            }else {
                ones++;
            }
        }
        char least_common = '1';
        if(zeros <= ones) least_common = '0';
        for(int j = 0; j < co2_vector.size(); j++) {
            if(co2_vector[j][i] == least_common) {
                temp.push_back(co2_vector[j]);
            }
        }
        co2_vector = temp;
    }

    int oxygen = stoi(oxygen_vector[0],0,2);
    int co2 = stoi(co2_vector[0],0,2);

    cout << "Part one: " << (delta * gamma) << endl;
    cout << "Part two: " << (oxygen*co2) << endl;
    return 0;
}
