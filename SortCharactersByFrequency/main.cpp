/*
 * Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 *
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> histogram = {};
        vector<int> indices = {};
        string result = "";

        for(int i = 0; i < 128; i++){
            histogram.push_back(0);
            indices.push_back(i);
        }

        for(char c : s)
            histogram[c]++;

        sort(indices.begin(), indices.end(), [&histogram](int i, int j){return histogram[i] > histogram[j];});

        for(int i = 0; i < histogram.size(); i++){
            if(histogram[indices[i]] != 0)
                for(int j = 0; j < histogram[indices[i]]; j++)
                    result += char(indices[i]);
        }
    return result;
    }

};

int main(){
    Solution s;
    s.frequencySort("raaeaedere");
}