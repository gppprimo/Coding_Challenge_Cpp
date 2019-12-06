#include "Functions.h"

int day_six1(){
    vector<string> input = read_input(path_to_file, file_d61);
    vector<pair<string, string>> input_data;    // second orbits first ( "F)S" )
    unordered_map<string, string> mappina;

    for(const string &s : input){
        vector<string> input_string = split(s, ')');
        input_data.emplace_back(input_string[0], input_string[1]);
    }

    for(const auto &p : input_data)
        mappina[p.second] = p.first;

    int dir_indir_orbits = 0;
    for(const auto &m : mappina) {
        int path_obits = 1;
        auto mm = mappina.find(m.second);
        while(mm != mappina.end()){
            ++path_obits;
            mm = mappina.find(mm->second);
        }
        dir_indir_orbits += path_obits;
    }
    return dir_indir_orbits;
}

vector<pair<string, int>> compute_distance(unordered_map<string, string> &mappina, string &start){
    auto m = mappina.find(start);
    vector<pair<string, int>> distances = {};
    int path_obits = 0;
    while(m != mappina.end()){
        distances.emplace_back(m->first, path_obits);
        m = mappina.find(m->second);
        ++path_obits;
    }
    return distances;
}

int day_six2(){
    vector<string> input = read_input(path_to_file, file_d61);
    vector<pair<string, string>> input_data;    // second orbits first ( "F)S" )
    unordered_map<string, string> mappina;

    for(const string &s : input){
        vector<string> input_string = split(s, ')');
        input_data.emplace_back(input_string[0], input_string[1]);
    }

    for(const auto &p : input_data)
        mappina[p.second] = p.first;

    string s1 = "YOU";
    string s2 = "SAN";
    auto dist_a = compute_distance(mappina, mappina[s1]);
    auto dist_b = compute_distance(mappina, mappina[s2]);

    for(auto a : dist_a){
        for(auto b : dist_b)
            if(a.first == b.first) return a.second + b.second;
    }
    return 0;
}