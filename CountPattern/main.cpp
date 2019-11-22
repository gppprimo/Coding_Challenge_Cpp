/*
 * Count the consecutive occurrences in line following this pattern
 *
 * d = 3, n = 3
 * 13
 * 1113
 * 3113
 *
 * */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// n: number of iterations
// d: starting point


vector<string> compute_pattern(unsigned int d, unsigned int n){
    vector<string> result;
    stringstream ss;
    ss << d;
    string current_str = ss.str();
    result.push_back(current_str);

    for(unsigned int i = 0; i < n; ++i){
        current_str = result[i];
        char current_char = current_str[0];
        unsigned int occurrences = 1;
        ss.str("");

        for(unsigned int j = 1; j < current_str.size(); ++j){
            if(current_char == current_str[j])
                ++occurrences;
            else{
                ss << occurrences << current_char;
                occurrences = 1;
            }
            current_char = current_str[j];
        }
        ss << occurrences << current_str.back();
        result.push_back(ss.str());
    }
    return result;
}

int main() {
    vector<string> v = compute_pattern(3, 4);
    for(const string & s : v)
        cout << s << endl;
    return 0;
}