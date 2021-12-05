#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int min(int a, int b) {
    if(a > b) return b;
    return a;
}
int max(int a, int b) {
    if(a > b) return a;
    return b;
}

class Terrain { 
    public:
        int **positions;
        int overlapping = 0;
    Terrain() {
        positions = new int*[1000];
        for(size_t i = 0; i < 1000; i++) {
            positions[i] = new int[1000];
        }
    }
    ~Terrain() {
        for(size_t i = 0; i < 1000; i++) {
            delete positions[i];
        }
        delete positions;
    }
    void addLineIfStraight(int x1, int y1, int x2, int y2) {
        if(x1 == x2) {
            int larger = max(y1,y2);
            for(int y = min(y1,y2); y <= larger; y++) {
                positions[x1][y]++;
                if(positions[x1][y] == 2) overlapping++;
                
            }
        }else if(y1 == y2) {
            int larger = max(x1,x2);
            for(int x = min(x1,x2); x <= larger; x++) {
                positions[x][y1]++;
                if(positions[x][y1] == 2) overlapping++; 
            }
        }
    }
    void addLine(int x1, int y1, int x2, int y2) {
        if(x1 == x2 || y1 == y2) {
            addLineIfStraight(x1,y1,x2,y2);
            return;
        }
        int bigX;
        int currentY;
        if(x1 > x2) {
            bigX = x1;
            currentY = y2;
        }else{
            bigX = x2;
            currentY = y1;
        }
        int dy = 1;
        if(x1 > x2) {
            if(y1 < y2)
                dy = -1;
        }else{
            if(y1 > y2)
                dy = -1;
        }
        for(int x = min(x1,x2); x <= bigX; x++) {
            positions[x][currentY]++;
            if(positions[x][currentY] == 2) {
                overlapping++;
            }
            currentY += dy;
        }
    }
    int overlappingLineCount() {
        return overlapping;
    }
};

int main() {
    ifstream file("input5.txt");
    string line;
    Terrain terrainPt1;
    Terrain terrainPt2;
    while(getline(file,line)) {
        int delimiterIndex = line.find(" -> ");
        string firstPart = line.substr(0,delimiterIndex);
        string secondPart = line.substr(delimiterIndex+4,line.size()-1);
        stringstream ss1(firstPart);
        stringstream ss2(secondPart);
        int x1,x2,y1,y2;
        ss1 >> x1;
        ss2 >> x2;
        ss1.ignore();
        ss2.ignore();
        ss1 >> y1;
        ss2 >> y2;
        terrainPt1.addLineIfStraight(x1,y1,x2,y2);
        terrainPt2.addLine(x1,y1,x2,y2);
    }
    cout << "Part One: " << terrainPt1.overlappingLineCount() << endl;
    cout << "Part Two: " << terrainPt2.overlappingLineCount() << endl;
    return 0;
}