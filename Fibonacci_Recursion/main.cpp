#include <iostream>
#include <vector>
using namespace std;

// senza memoizzazione
unsigned int fibonacci(unsigned int n){
    if(n == 0 or n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// con memoizzazione
unsigned int memoized_fibonacci(unsigned int n, vector<unsigned int> &temp_res) {
    if(n == 0 or n == 1)
        return n;

    if(not temp_res[n])
        temp_res[n] = memoized_fibonacci(n - 1, temp_res) + memoized_fibonacci(n - 2, temp_res);
    return temp_res[n];
}

int main() {
    unsigned int n = 500;
    vector<unsigned int> v(n + 1, 0);
//    std::cout << memoized_fibonacci(n, v); // relativamente poco tempo
    std::cout << fibonacci(n); // tantissimo tempo in piu' rispetto a prima
    return 0;
}