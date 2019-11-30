/*
 * Given a list of pairs of integers (mi, mj), where mi represent the pc ID which infected
 * the pc with ID mj.
 * The challenge is to return the list of IDs of the pc that started the infection.
 * For example:
 *
 * in: [(1, 2), (3, 1), (2, 4), (6, 2)]
 * out: [3, 6]
 *
 * */


#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;

vector<int> check_infection(const vector<pair<int, int>> &input_list){  // S: O(n), T: O(n)
    unordered_set<int> infected;    // S: O(n)
    vector<int> results = {};       // S: O(n)
    for(const auto & p : input_list)    // T: O(n)
        infected.insert(p.second);      // T: O(1)
    for(const auto & il : input_list){  // T: O(n)
        if(infected.find(il.first) == infected.end())
            results.push_back(il.first);    // T: O(1)
    }
    return results;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}