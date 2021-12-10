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
    ifstream file("input10.txt");
    string line;

    int score = 0;
    vector<long long int> scores;
    while(getline(file,line)) {
        stack<char> s;
        bool lineComplete = false;
        for(int i = 0; i < line.size(); i++) {
            if(lineComplete) break;
            switch(line[i]) {
                case '(':
                case '[':
                case '{':
                case '<': 
                    s.push(line[i]);
                    break;
                case ')':
                case ']':
                case '}':
                case '>':
                    int d = 2;
                    if(line[i] == ')') d = 1;
                    if(s.top() != line[i]-d) {
                        switch(line[i]) {
                            case ')': score += 3; break;
                            case ']': score += 57; break;
                            case '}': score += 1197; break;
                            case '>': score += 25137; break;
                        }
                        lineComplete = true;
                    }
                    s.pop();
                    
                    break;
            }
        }
        if(!lineComplete) {
            long long int linescore = 0;
            while(!s.empty()) {
                linescore *= 5;
                switch(s.top()) {
                    case '(': linescore += 1; break;
                    case '[': linescore += 2; break;
                    case '{': linescore += 3; break;
                    case '<': linescore += 4; break;                        
                }
                s.pop();
            }
            scores.push_back(linescore);
        }
    }

    sort(scores.begin(),scores.end());

    cout << "Part One: " << score << endl;
    cout << "Part Two: " << scores[scores.size()/2] << endl;

    return 0;
}
