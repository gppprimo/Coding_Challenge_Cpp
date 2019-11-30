#include <iostream>
#include <string>

using std::string;


int camelcase(string s) {   // O(n)
    int count = s.empty() ? 0 : 1;  // O(1)
    for(char c : s){                // O(n)
        if(int(c) >= 65 and int(c) <= 90)
            ++count;
    }
    return count;
}


int main() {
    std::cout << camelcase ("helloWorld") << std::endl;
    return 0;
}