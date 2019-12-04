#include "Functions.h"

//int _compute(int x, int y) {return x + y / 3 - 2;};
int _compute2(int x, int y) {
    int result = 0;
    while((y = y/3 - 2) >= 0)
        result += y;
    return result + x;
}

int day_one1(){
    vector<string> lines = read_input(path_to_file, file_d11);
    vector<int> values = {};
    for(const string &s : lines)
        values.push_back(stoi(s));

//    return std::accumulate(lines.begin(), lines.end(), 0, _compute);
    return std::accumulate(values.begin(), values.end(), 0, [](int x, int y){return x + y / 3 -2;});
}

int day_one2(){
    vector<string> lines = read_input(path_to_file, file_d11);
    vector<int> values = {};
    for(const string &s : lines)
        values.push_back(stoi(s));
    return std::accumulate(values.begin(), values.end(), 0, _compute2);
}