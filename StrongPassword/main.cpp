#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;



int check_correctness(string &s){
    vector<bool> check_sc_uc_lc_num = {false, false, false, false};
    int count = 0;
    for(char c : s){
        int c_code = c;
        if(c_code >= 48 and c_code <= 57)   // ascii numbers
            check_sc_uc_lc_num[3] = true;
        if(c_code >= 65 and c_code <= 90)   // ascii upper case
            check_sc_uc_lc_num[1] = true;
        if(c_code >= 97 and c_code <= 122)  // ascii lower case
            check_sc_uc_lc_num[2] = true;
        if((c_code >= 35 and c_code <= 38) or(c_code >= 40 and c_code <= 43) or (c_code == 45) or (c_code == 64))   // ascii special
            check_sc_uc_lc_num[0] = true;
    }
    for(bool b : check_sc_uc_lc_num){
        if(not b)
            ++count;
    }
    return count;
}

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    if(password.size() < 6)
        return (6 - int(password.size()));
    return check_correctness(password);
}

int main() {
    std::cout << minimumNumber(11, "#HackerRank")<< std::endl;
    return 0;
}