#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int result = 1;
        if(s == "")
            return 0;
        else{
            set<char> temp;
            for(int i = 0; i < s.size() - 1; i++){
                result = 1;
                temp.insert(s[i]);
                for(int j = i + 1; j < s.size(); j++){
                    if(temp.find(s[j]) == temp.end()){
                        temp.insert(s[j]);
                        result++;
                    }
                    else {
                        temp.erase(temp.begin(), temp.end());
                        break;
                    }
                }
                if(result > max)
                    max = result;
            }
        }
        if(result > max)
            return result;
        else
            return max;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring(" ");
    return 0;
}