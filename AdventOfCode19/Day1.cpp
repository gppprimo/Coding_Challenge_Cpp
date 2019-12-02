#include "Functions.h"

using namespace std;

// reading input file
vector<int> read_lines(){
    vector<int> lines;
    ifstream file;
    string line;
    file.open("../Input/Day1_1.txt");
    if (file.is_open()){
        while (getline (file, line))
            lines.push_back(std::stoi(line));
        file.close();
    } else std::cout << "Unable to open file";
    return lines;
}

//int _compute(int x, int y) {return x + y / 3 - 2;};
int _compute2(int x, int y) {
    int result = 0;
    while((y = y/3 - 2) >= 0)
        result += y;
    return result + x;
}

int day_one1(){
    vector<int> lines = read_lines();
//    return std::accumulate(lines.begin(), lines.end(), 0, _compute);
    return std::accumulate(lines.begin(), lines.end(), 0, [](int x, int y){return x + y / 3 -2;});
}

int day_one2(){
    vector<int> lines = read_lines();
    return std::accumulate(lines.begin(), lines.end(), 0, _compute2);
}