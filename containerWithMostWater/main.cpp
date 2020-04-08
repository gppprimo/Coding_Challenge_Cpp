/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, dim = height.size();
        for(int i = 0; i < dim - 1; i++){
            for(int j = i; j < dim; j++){
                int tempArea = 0, x = i - j;
                if(height[i] >= height[j])
                    tempArea = height[j] * x;
                else
                    tempArea = height[i] * x;
                if(tempArea > maxArea)
                    maxArea = tempArea;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> v;
    string input;

    getline(cin, input);
    int n = input.size();
    while(--n)
        v.push_back(int(input[n]));

    cout << s.maxArea(v);
}