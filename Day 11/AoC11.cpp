#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("input11.txt");
    string line;

    int octopuses[10][10];

    int y = 0;
    while(getline(file, line)) {
        for(int x = 0; x < 10; x++) {
            octopuses[y][x] = line[x] - '0';
        }
        y++;
    }
    int totalFlashes = 0;

    int pt2Result = -1;

    int flashesInStep = 0;
    for(int i = 0; ; i++) {
        flashesInStep = 0;
        for(int y = 0; y < 10; y++) {
            for(int x = 0; x < 10; x++) {
                octopuses[y][x]++;
            }
        }
        bool finished = false;
        while(!finished) {
            finished = true;
            for(int y = 0; y < 10; y++) {
                for(int x = 0; x < 10; x++) {
                    if(octopuses[y][x] >= 10) {
                        finished = false;
                        if(x > 0) octopuses[y][x-1]++;
                        if(x < 9) octopuses[y][x+1]++;
                        if(y > 0) octopuses[y-1][x]++;
                        if(y < 9) octopuses[y+1][x]++;
                        if(x > 0 && y > 0) octopuses[y-1][x-1]++;
                        if(x > 0 && y < 9) octopuses[y+1][x-1]++;
                        if(x < 9 && y > 0) octopuses[y-1][x+1]++;
                        if(x < 9 && y < 9) octopuses[y+1][x+1]++;
                        octopuses[y][x] = -9999;
                        totalFlashes++;
                        flashesInStep++;
                    }
                }
            }
        }
        for(int y = 0; y < 10; y++) {
            for(int x = 0; x < 10; x++) {
                if(octopuses[y][x] < 0) octopuses[y][x] = 0;
            }
        }
        if(i == 99) {
            cout << "Part One: " << totalFlashes << endl;
        }
        if(flashesInStep == 100) {
            cout << "Part Two: " << (i+1) << endl;
            return 0;
        }
    }
    return 0;
}
