#include <iostream>


/*
Devi restituire il risultato sommatoria(i=1,...,n) sommatoria(j=i,...,n) max(V[i], V[i + 1], ..., V[j])
i indice di partenza del subarray, j finale

Esempio
    V = [2, 4, 3]
Risultato: 16
[ 2 ]
[ 2 , 4]
[ 2 , 4, 3]
[ 4 ]
[4, 3]
[ 3 ]
 */


#include <vector>
#include <algorithm>
using std::vector;

// T: O(NlogN), s: O(1)
int vect_sums(vector<int> v){
    // T: O(Nlog N)
    std::sort(v.begin(), v.end());
    int res = 0;
    // T: O(N)
    for(int i = 0; i < v.size(); ++i)
        res += v[i] * (v.size() - i);
    return res;
}


int main() {
    std::cout << vect_sums({-1, -2,-3});
    return 0;
}
