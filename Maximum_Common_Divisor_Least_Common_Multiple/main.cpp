/*
 * Euclide's Algorithm to compute the MCD and LCM
 *
 * */

#include <iostream>
#include <vector>

using namespace std;


// mcd iterative
int mcd(int a = 1, int b = 1){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
};

// mcd recursively
int mcd_rec(int a = 1, int b = 1){
    if(not b)
        return a;
    return mcd_rec(b, a % b);
};


int mcd_set(vector<int> v){
    if(v.size() <= 2)
        return mcd(v.front(),v.back());
    int res = v.front();
    for(size_t i = 1; i < v.size(); ++i)
        res = mcd(res, v[i]);
    return res;
};

// lcd
inline int lcd(int a, int b) {return (a * b) / mcd(a, b);};


int lcd_set(vector<int> v){
    if(v.size() <= 2)
        return lcd(v.front(),v.back());
    int res = v.front();
    for(size_t i = 1; i < v.size(); ++i)
        res = lcd(res, v[i]);
    return res;
}


int main() {
    std::cout << lcd_set( {1, 4, 3});
    return 0;
}