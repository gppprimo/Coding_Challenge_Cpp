//
// Created by Giuseppe Primo on 02/12/2019.
//

#ifndef ADVENTOFCODE19_FUNCTIONS_H
#define ADVENTOFCODE19_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>
#include <sstream>
#include <unordered_set>
#include <map>
#include <set>
#include <unordered_map>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::pair;
using std::unordered_set;
using std::map;
using std::set;
using std::unordered_map;

constexpr const char * path_to_file = "../Input/";
constexpr const char * test_file = "test.txt";
constexpr const char * file_d11 = "Day1_1.txt";
constexpr const char * file_d21 = "Day2_1.txt";
constexpr const char * file_d31 = "Day3_1.txt";
constexpr const char * file_d41 = "Day4_1.txt";
constexpr const char * file_d51 = "Day5_1.txt";
constexpr const char * file_d61 = "Day6_1.txt";

// support functions
vector<string> read_input(const char * path_t_f, const char * fn);
vector<string> split(const string & s, char token);
vector<int> build_vector(const vector<string> & s);
//

int day_one1();
int day_one2();

int day_two1(int noun = 12, int verb = 2);
int day_two2();

int day_three1();
int day_three2();

int day_four1();
int day_four2();

void day_five1();
void day_five2();

int day_six1();
int day_six2();

#endif //ADVENTOFCODE19_FUNCTIONS_H
