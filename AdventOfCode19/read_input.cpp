#include "Functions.h"

template <class T>
vector<T> read_input(){
        vector<T> lines;
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