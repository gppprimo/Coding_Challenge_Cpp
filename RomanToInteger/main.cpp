#include <iostream>
#include <string.h>

using namespace std;

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000


int translateChar(const char &c){
    switch (c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            return 0;
    }
}

class Solution {
public:
    int romanToInt(string s) {
        // input :: roman number
        int sum = 0;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if(prev == 'I' and (s[i] == 'V' or s[i] == 'X')){
                sum -= I;
            } else if(prev == 'X' and (s[i] == 'L' or s[i] == 'C')){
                sum -= X;
            } else if(prev == 'C' and (s[i] == 'M' or s[i] == 'D')){
                sum -= C;
            } else {
                sum += translateChar(prev);
            }
            prev = s[i];
        }
        sum += translateChar(prev);
        return sum;
    }
};


int main() {
    string input;
    Solution s;
    cin >> input;
    cout << s.romanToInt(input);
    return 0;
}