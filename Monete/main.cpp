// hai un set di possibili monete a disposizione da 1, 2, 5, 10, 20, 50, 100 e 200
// rappresentare una cifra qualsiasi in input col minor numero possibile di monete

#include <iostream>
#include <vector>

using namespace std;


unsigned int find_coin(int n, const vector<unsigned int> & coins){
    if(n > coins.back())
        return coins.back();
    if(n < coins.front())
        return coins.front();
    for(unsigned int i = coins.size() - 1; i >= 0; --i){
        if(coins[i] > n)
            return coins[i];
    }
    return coins.front();
}

unsigned int min_num_coins(int n, const vector<unsigned int> &coins){
    int count = 0;
    while(n > 0){
        n -= find_coin(n, coins);
        ++count;
    }
    return count;
}


int main() {
    cout << min_num_coins(29, {1, 2, 5, 10, 20, 50, 100, 200});
    return 0;
}