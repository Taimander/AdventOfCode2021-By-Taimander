#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class board {
    public:
        int values[5][5] = {};
        int marks[5][5] = {};

        void setValues(string lines[]) {
            for(int i = 0; i < 5; i++) {
                stringstream ss(lines[i]);
                for(int j = 0; j < 5; j++) {
                    ss >> values[i][j];
                    if (ss.peek() == ' ')
                        ss.ignore();
                }
            }
        }
        void markNumber(int i) {
            for(int y = 0; y < 5; y++) {
                for(int x = 0; x < 5; x++) {
                    if(values[y][x] == i) {
                        marks[y][x] = 1;
                    }
                }
            }
        }
        bool hasWon() {
            for(int y = 0; y < 5; y++) {
                int won = 1;
                for(int x = 0; x < 5; x++) {
                    if(marks[y][x] != 1) {
                        won = 0;
                        break;
                    }
                }
                if(won) return true;
                won = 1;
                for(int x = 0; x < 5; x++) {
                    if(marks[x][y] != 1) {
                        won = 0;
                        break;
                    }
                }
                if(won) return true;
            }
            return false;
        }
        int computePartialScore() {
            int sum_of_unmarked = 0;
            for(int y = 0; y < 5; y++) {
                for(int x = 0; x < 5; x++) {
                    if(marks[y][x] != 1) {
                        sum_of_unmarked += values[y][x];
                    }
                }
            }
            return sum_of_unmarked;
        }
        void resetMarks() {
            for(int y = 0; y < 5; y++) {
                for(int x = 0; x < 5; x++) {
                    marks[y][x] = 0;
                }
            }
        }
};

int main() {
    ifstream file("input4.txt");
    string line;
    vector<int> numbers;
    getline(file,line);
    stringstream ss(line);

    for (int i; ss >> i;) {
        numbers.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }
    vector<board> boards;
    while(getline(file, line)) {
        string lines[5];
        for(int i = 0; i < 5; i++) {
            getline(file,lines[i]);
        }
        board b;
        b.setValues(lines);
        boards.push_back(b);
    }
    file.close();
    bool winner = false;
    for(int i = 0; i < numbers.size() && !winner; i++) {
        int num = numbers[i];
        for(int j = 0; j < boards.size(); j++) {
            boards[j].markNumber(num);
            if(boards[j].hasWon()) {
                cout << "Part One: " << (boards[j].computePartialScore()*num) << endl;
                winner = true;
                break;
            }
        }
    }

    // PART 2
    for(int k = 0; k < boards.size(); k++) {
        boards[k].resetMarks();
    }

    int winnerCount;
    for(int i = 0; i < numbers.size(); i++) {
        winnerCount = 0;
        for(int j = 0; j < boards.size(); j++) {
            boards[j].markNumber(numbers[i]);
            if(boards[j].hasWon()) winnerCount++;
        }
        if(winnerCount == boards.size()-1) {
            for(board b : boards) {
                if(!b.hasWon()) {
                    while(!b.hasWon()) {
                        b.markNumber(numbers[i++]);
                    }
                    cout << "Part Two: " << (b.computePartialScore() * numbers[i-1]) << endl;
                }
            }
            break;
        }
    }
    
    return 0;
}