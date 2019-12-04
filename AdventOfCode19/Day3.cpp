#include "Functions.h"

vector<pair<int, int>> build_path(vector<string> &codes){
    vector<pair<int, int>> path = {};
    int curr_y = 0, curr_x = 0;

    for(string code : codes){
        char direction = code[0];
        stringstream ss;
        for(char c : code){
            if(c >= 48 and c <= 57 )
                ss << c;
        }
        int distance = stoi(ss.str());
        if(direction == 'U'){
            for(int i = 0; i < distance; ++i)
                path.push_back({curr_x, curr_y += 1});
        } else if (direction == 'D'){
            for(int i = 0; i < distance; ++i)
                path.push_back({curr_x, curr_y -= 1});
        } else if(direction == 'R'){
            for(int i = 0; i < distance; ++i)
                path.push_back({curr_x += 1, curr_y});
        } else if(direction == 'L') {
            for (int i = 0; i < distance; ++i)
                path.push_back({curr_x -= 1, curr_y});
        }
    }
    return path;
}

int count_steps(const vector<pair<int, int>> &path, pair<int, int> point){
    for(size_t i = 0; i < path.size(); ++i){
        if(path[i].first == point.first and path[i].second == point.second)
            return i + 1;
    }
    return 0;
}

int day_three1() {

    vector<string> lines = read_input(path_to_file, file_d31);
    vector<string> codes1 = split(lines[0], ',');
    vector<string> codes2 = split(lines[1], ',');

    vector<pair<int, int>> path1 = build_path(codes1);
    vector<pair<int, int>> path2 = build_path(codes2);

    int min_cp = INT_MAX;
    for(auto c1 : path1){
        for(auto c2 : path2){
            if(c1.first == c2.first and c1.second == c2.second){
                int dist = abs(c1.first) + abs(c1.second);
                if(dist < min_cp)
                    min_cp = dist;
            }
        }
    }
    return min_cp;
}

int day_three2(){
    vector<string> lines = read_input(path_to_file, file_d31);
    vector<string> codes1 = split(lines[0], ',');
    vector<string> codes2 = split(lines[1], ',');

    vector<pair<int, int>> path1 = build_path(codes1);
    vector<pair<int, int>> path2 = build_path(codes2);
    vector<pair<int, int>> intersections = {};

    for(auto c1 : path1){
        for(auto c2 : path2){
            if(c1.first == c2.first and c1.second == c2.second)
                intersections.push_back({c1});
        }
    }

    int min_steps_number = INT_MAX;
    for(auto common_point : intersections){
        int steps1 = count_steps(path1, common_point);
        int steps2 = count_steps(path2, common_point);
        min_steps_number = (steps1 + steps2 < min_steps_number) ? steps1 + steps2 : min_steps_number;
    }
    return min_steps_number;
}
