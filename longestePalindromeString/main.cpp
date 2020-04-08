/*
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 * */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int histogram[256]{};
        int count = 0;

        if(s.size() == 1)
            return 1;

        for(char c : s)
            histogram[c]++;

        for(int h : histogram) {
            count += h / 2 * 2;
            if (h % 2 == 1)
                count += 1;
        }
        if (count == s.size())
            return --count;
        return count;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("aaa");
    return 0;
}