//
// Created by Giuseppe Primo on 02/12/2019.
//
#include "Functions.h"
#include <sstream>

using std::stringstream;

vector<string> read_lines_day2(){
    vector<string> lines;
    ifstream file;
    string line;
    file.open("../Input/Day2_1.txt");
    if (file.is_open()){
        while (getline (file, line))
            lines.push_back(line);
        file.close();
    } else std::cout << "Unable to open file";
    return lines;
}

vector<string> split(const string & s, char token) {
    vector<string> result;
    stringstream ss;
    for (char c : s)
        if (c != token)
            ss << c;
        else {
            string tmp = move(ss.str());
            if (not tmp.empty())
                result.push_back(move(tmp));
            ss.str("");
        }
    string tmp = move(ss.str());
    if (not tmp.empty())
        result.push_back(move(tmp));
    return result;
}

vector<int> build_vector(const vector<string> &s){
    vector<int> v;
    for(string ss : s)
        v.push_back(stoi(ss));
    return v;
}

int day_two1(int noun = 12, int verb = 2){
    vector<string> vs = read_lines_day2();
    vector<int> v = build_vector(split(vs[0], ','));
    v[1] = noun;
    v[2] = verb;
    for(size_t i = 0; i < v.size(); i += 4){
        if(v[i] == 1)
            v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
        else if(v[i] == 2)
            v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
        else if(v[i] == 99)
            break;
    }
    return v[0];
}

int day_two2(){
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(day_two1(i, j) == 19690720)
                return 100 * i + j;
        }
    }
    return 0;
}