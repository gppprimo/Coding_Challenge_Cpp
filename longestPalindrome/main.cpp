/*
 * Given a string which consists of lowercase or uppercase letters, find the length
 * of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 * */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[256]{};
        int sum = 0;
        bool center = false;

        for(char c : s){
            count[c]++;
        }

        for(int v : count){
            sum += v / 2 * 2;
            if(v % 2 == 1)
                center = true;
        }
        return sum + center;
    }
};


int main() {


    return 0;
}