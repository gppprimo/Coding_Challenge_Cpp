/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 * */
#include <iostream>
#include <math.h>

// 3 multiples : 3/2 N/3(N/3 + 1)
// 5 multiples : 5/2 N/5(N/5 + 1)


inline unsigned int SOMMA_DA_0_A_N(int n) { return n * (n + 1) / 2; }

unsigned int sum_multiples(int n){
    int nn = n - 1;
    return 3 * SOMMA_DA_0_A_N(nn/3) + 5 * SOMMA_DA_0_A_N(nn/5) - 15 * SOMMA_DA_0_A_N(nn/15);
}

int main() {
    std::cout << sum_multiples(1000);
    return 0;
}