/*
 * Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.



Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:



Note:

The total number of elements of the given matrix will not exceed 10,000.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> results = {};
        int t = matrix.size();
        if(matrix.empty())
            return results;

        if(matrix.size() == 1){
            results = matrix[0];
            return results;
        }

        for(int i = 0; i < matrix.size(); i++){
            if(i % 2 != 0){
                for(int j = i; j >= 0; j--)
                    results.push_back(matrix[i - j][j]);
            } else
                for(int j = 0; j <= i; j++)
                    results.push_back(matrix[i - j][j]);
        }

        return results;
    }
};


int main() {
    Solution s;
    vector<vector<int>> mat = {{2,5},{8,4},{0,-1}};
    s.findDiagonalOrder(mat);
    return 0;
}