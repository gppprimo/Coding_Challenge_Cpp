/*
 * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

 * */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        else{
            int haystackDim = haystack.size();
            int needleDim = needle.size();
            for(int i = 0; i < haystackDim - needleDim + 1; i++) {
                for (int j = 0; j < needleDim; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                    else if(needleDim - 1 == j)
                        return i;
                }

            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("a", "ab");
    return 0;
}