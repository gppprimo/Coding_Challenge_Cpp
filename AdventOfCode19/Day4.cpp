#include "Functions.h"

vector<string> read_lines_day4(){
    vector<string> lines;
    ifstream file;
    string line;
    file.open("../input_test/Day4_1.txt");
    if (file.is_open()){
        while (getline (file, line))
            lines.push_back(line);
        file.close();
    } else std::cout << "Unable to open file";
    return lines;
}

bool check_password(const long x){
    stringstream ss;
    ss << x;
    string xs = ss.str();
    bool one_double = false;
    for(size_t i = xs.size() - 1; i >= 1; --i){
        int a = xs[i] - '0';
        int b = xs[i - 1] - '0';
        if(a < b)
            return false;
        if(a == b)
            one_double = true;
    }
    return one_double;
}

int check_password2(const long x) {
    stringstream ss;
    ss << x;
    string xs = ss.str();
    int double_digits = 1, min_double_digits = INT_MAX;
    for (size_t i = xs.size() - 1; i >= 1; --i) {
        int a = xs[i] - '0';
        int b = xs[i - 1] - '0';
        if (a < b)
            return false;
        if (a == b)
            ++double_digits;
        else {
            if(double_digits != 1 and double_digits < min_double_digits){
                min_double_digits = double_digits;
                double_digits = 1;
            }
        }
    }
    if(double_digits != 1 and double_digits < min_double_digits)
        min_double_digits = double_digits;
    return min_double_digits == 2;
}


int day_four1(){
    vector<string> input = read_input(path_to_file, file_d41);
    vector<string> input_string = split(input[0], '-');
    long int a = std::stol(input_string[0]);
    long int b = std::stol(input_string[1]);

    int count = 0;
    while(++a <= b){
        if(check_password(a))
            ++count;
    }
    return count;
}


int day_four2(){
    vector<string> input = read_input(path_to_file, file_d41);
    vector<string> input_string = split(input[0], '-');
    long int a = std::stol(input_string[0]);
    long int b = std::stol(input_string[1]);

    int count = 0;
    while(++a <= b){
        if(check_password2(a))
            ++count;
    }
    return count;


}