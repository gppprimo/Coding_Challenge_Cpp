/*
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.

 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
            if(*it == val){
                nums.erase(it);
                --it;
            }

        }
        return nums.size();
    }
};


int main() {
    Solution s;
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    cout << s.removeElement(v, 5);
    return 0;
}