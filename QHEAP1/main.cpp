#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void printMax(stack<int> &max_stack){
    if(max_stack.empty())
        return;
    cout << max_stack.top() << endl;
}

void deleteTop(stack<int> &s, stack<int> s2){
    if(!s.empty())
        s.pop();
    if(!s2.empty())
        s2.pop();
}

void add(stack<int> &s, stack<int> s_max, int x){
    if(!s.empty() and s.top() > x)
        s_max.push(s.top());
    else
        s_max.push(x);
    s.push(x);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack<int> originale, pezzotto, aggiuntivo;
    int N, q, x;
    cin >> N;
    while(N--){
        cin >> q;
        if(q == 1){
            cin >> x;
            add(originale, pezzotto, x);
        }
        else if(q == 2)
            deleteTop(originale, pezzotto);
        else if(q == 3)
            printMax(pezzotto);
    }
    return 0;
}
