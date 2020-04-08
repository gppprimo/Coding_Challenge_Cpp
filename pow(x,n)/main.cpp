/*
 * Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 *
 * */


#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    static double calc(double x, int n){
        double res = x;
        for(int i = 1; i < std::abs(n); i++)
            res *= x;
        return res;
    }

    double myPow(double x, int n) {
        if(x == 1 || n == 0)
            return 1;
        if(x == -1 and n % 2 == 0)
            return 1;
        if(x == -1 and n % 2 == 1)
            return -1;
        if(n <= -2147483648 || n >= 2147483647)
            return 0;
        if(n < 0)
            return 1/Solution::calc(x, abs(n));
        return Solution::calc(x, n);
    }
};


int main() {
    Solution s;
    cout << s.myPow(2.00000,
                    -2147483648);
    return 0;
}