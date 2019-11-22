#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned long dim = nums.size();
        int max = nums[0], sumMissing = 0, sumNotMissing = 0;

        if(dim == 0)
            return 0;

        for(int i : nums){
            if(i > max)
                max = i;
            sumMissing += i;
        }

        for(int i = 0; i <= dim; i++)
            sumNotMissing += i;

        return sumNotMissing - sumMissing;
    }
};


int main() {
    Solution s;
    vector<int> v = {3, 0 ,1};
    cout << s.missingNumber(v);
    return 0;
}