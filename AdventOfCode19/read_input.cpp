#include "Functions.h"

// read input files
vector<string> read_input(const char *path, const char *file_name){
    vector<string> lines;
    ifstream file;
    string line;
    file.open(string(path) + string(file_name));
    if (file.is_open()){
        while (getline (file, line))
            lines.push_back(line);
        file.close();
    } else std::cout << "Unable to open file";
    return lines;
}

// split a string specifying a token
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