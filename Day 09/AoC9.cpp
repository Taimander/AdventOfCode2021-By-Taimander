#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

#define X 10
#define Y 5

class Point {
    public:
    int x,y;

    Point(int xcoord, int ycoord) {
        x = xcoord;
        y = ycoord;
    }
};

int basinLength(int values[Y][X], int x, int y) {
    if(values[y][x] == 9) return 0;
    int length = 1;
    if(x > 0 && values[y][x-1] > values[y][x]) {
        length += basinLength(values,x-1,y);
    }
    if(x < (X-1) && values[y][x+1] > values[y][x]) {
        length += basinLength(values,x+1,y);
    }
    if(y > 0 && values[y-1][x] > values[y][x]) {
        length += basinLength(values,x,y-1);
    }
    if(y < (Y-1) && values[y+1][x] > values[y][x]) {
        length += basinLength(values,x,y+1);
    }
    return length;
}

int main() {
    ifstream file("testinput.txt");
    string line;
    int values[Y][X];

    int y = 0;
    while(getline(file,line)) {
        for(int x = 0; x < X; x++) {
            values[y][x] = line[x]-'0';
        }
        y++;
    }
    vector<Point> lowPoints;
    int resultPt1 = 0;
    for(y = 0; y < Y; y++) {
        for(int x = 0; x < X; x++) {
            if(y > 0 && values[y-1][x] <= values[y][x]) {
                continue;
            }
            if(x > 0 && values[y][x-1] <= values[y][x]) {
                continue;
            }
            if(y < (Y-1) && values[y+1][x] <= values[y][x]) {
                continue;
            }
            if(x < (X-1) && values[y][x+1] <= values[y][x]) {
                continue;
            }
            lowPoints.push_back(Point(x,y));
            resultPt1 += values[y][x]+1;
        }
    }

    vector<int> basinSizes;
    for(Point p : lowPoints) {
        basinSizes.push_back(basinLength(values,p.x,p.y));
    }
    sort(basinSizes.begin(),basinSizes.end());

    int resultPt2 = 1;
    for(int i = 1; i <= 3; i++) {
        resultPt2 *= basinSizes[basinSizes.size()-i];
    }

    cout << basinLength(values,9,0) << endl;

    cout << "Part One: " << resultPt1 << endl;
    cout << "Part Two: To be implemented..." << endl;
    return 0;
}