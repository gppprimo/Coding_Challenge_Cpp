#include <iostream>
#include <string.h>

using std::string;
using std::cout;


class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int temp = 0;
        if(num % 1000 < 1000) {
            for(int i = 0; i < num / 1000; i++)
                roman.append("M");
        }

        else if(num % 100 < 100){
            if(num / 100 < 400){
                for(int i = 0; i < num / 100; i++)
                    roman.append("C");
            }
            if(num / 100 == 400){
                roman.append("CD");
            }
            else if(num == 500)
                roman.append("D");
            else if(num / 100 > 500 and num / 100 < 900) {
                for (int i = 0; i < num / 100 - 5; i++) {
                    roman.append("C");
                }
            }
            else if(num / 100 == 900){
                    roman.append("CM");
                }
            }

        else if(num % 10 < 10){
            if(num / 10 < 4){
                for(int i = 0; i < num / 10; i++)
                    roman.append("X");
            }
            else if(num / 10 == 4){
                roman.append("XL");
            }
            else if(num / 10 == 5)
                roman.append("L");
            else if(num / 10 > 6 and num / 10 < 9) {
                roman.append("LX");
                for (int i = 0; i < num / 10 - 5; i++) {
                    roman.append("X");
                }
            }
            else if(num / 10 == 9)
                roman.append("XC");
        }

        else if(num < 10){
            if(num < 4) {
                for (int i = 0; i < num; i++)
                    roman.append("I");
            }
            else if(num == 4)
                roman.append("IV");
            else if(num == 5)
                roman.append("5");
            else if(num > 5 and num < 9){
                if(num == 6)
                    roman.append("VI");
                else {
                    for (int i = 0; i < num - 5; i++)
                        roman.append("I");
                }
            }
            else if(num == 9)
                roman.append("IX");
        }

    }
};


int main() {
    Solution s;
    cout << s.intToRoman(500);
    return 0;
}