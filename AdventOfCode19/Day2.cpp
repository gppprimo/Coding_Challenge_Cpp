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
    file.open("../input_test/Day2_1.txt");
    if (file.is_open()){
        while (getline (file, line))
            lines.push_back(line);
        file.close();
    } else std::cout << "Unable to open file";
    return lines;
}

vector<int> build_vector(const vector<string> &s){
    vector<int> v;
    for(string ss : s)
        v.push_back(stoi(ss));
    return v;
}

int day_two1(int noun, int verb){
    vector<string> vs = read_input(path_to_file, file_d21);
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