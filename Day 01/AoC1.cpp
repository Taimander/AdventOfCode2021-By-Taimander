#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <string>

using namespace std;

int main() {
    ifstream file("input1.txt");
    string line;
    int increases = 0;
    getline(file, line);
    int last = atoi(line.c_str());
    int curr;

    int increases2 = 0;
    int l1 = 999999999;
    int l2 = 999999999;
    int l3 = last;

    while(getline(file, line)) {
        curr = atoi(line.c_str());
        if(last < curr) {
            increases++;
        }
        if( (l1+l2+l3) < (l2+l3+curr)) {
            increases2++;
        }
        l1 = l2;
        l2 = l3;
        l3 = curr;

        last = curr;
    }
    cout << "Part One: " << increases << endl;
    cout << "Part Two: " << increases2 << endl;
    file.close();
    return 0;
}