/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 * */

#include <iostream>
#include <vector>

using namespace std;

double computeMedian(vector<int>& nums){
    int dim = nums.size();
    if(dim % 2 != 0)
        return nums[dim / 2];
    else
        return (nums[dim / 2] + nums[(dim - 1) / 2]) / 2.0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int dim1 = nums1.size(), dim2 = nums2.size();
        int index = dim1 + dim2;
        vector<int> merged;
        int i = 0, j = 0;
        double median;

        if(dim1 == 0)
            return computeMedian(nums2);
        if(dim2 == 0)
            return computeMedian(nums1);

        for(int k = 0; k < index; k++){
            if(i >= dim1)
                merged.push_back(nums2[j++]);
            else if(j >= dim2)
                merged.push_back(nums1[i++]);
            else if(nums1[i] < nums2[j])
                    merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }
        return computeMedian(merged);
    }
};

int main() {
    Solution s;
    vector<int> n1, n2;
    n1 = {1, 3};
    n2 = {2};
    s.findMedianSortedArrays(n1, n2);
    return 0;
}