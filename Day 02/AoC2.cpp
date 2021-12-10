#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    ifstream file("input2.txt");
    string line;
    int depth = 0;
    int displacement = 0;

    int aim = 0;
    int depth2 = 0;
    int displacement2 = 0;

    while(getline(file, line)) {
        int val;
        switch(line[0]) {
            case 'f': // forward
            val = line[8]-'0';
            displacement += val;

            displacement2 += val;
            depth2 += aim * val;
            break;
            case 'd': // down
            val = line[5]-'0';
            depth += val;

            aim += val;
            break;
            case 'u': // up
            val = line[3]-'0';
            depth -= val;

            aim -= val;
            break;
        }
    }

    cout << "Part one: " << (depth*displacement) << endl;
    cout << "Part two: " << (depth2*displacement2) << endl;

    file.close();
    return 0;
}