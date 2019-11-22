#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;



string timeInWords(int h, int m) {
    static const string past = "past";
    static const string to = "to";
    static const string o_clock = "o' clock";
    static const string minute = "minute";
    static const string minutes = "minutes";
    static const string half = "half";
    static const string quarter = "quarter";
    std::unordered_map<int, string> mappina = {
            {1, "one"},
            {2, "tow"},
            {3, "three"},
            {4, "four"},
            {5, "five"},
            {6, "six"},
            {7, "seven"},
            {8, "eight"},
            {9, "nine"},
            {10, "ten"},
            {11, "eleven"},
            {12, "twelve"},
            {13, "thirteen"},
            {14, "fourteen"},
            {15, "quarter"},
            {16, "sixteen"},
            {17, "seventeen"},
            {18, "eighteen"},
            {19, "nineteen"},
            {20, "twenty"},
            {30, "thirty"},
            {40, "fourty"},
            {50, "fifty"}
    };

    string response = "";

    if(m == 0)
        return mappina[h] + " " + o_clock;
    else if(m == 1)
        return mappina[m] + " " + minute + " " + past + " " + mappina[h];
    else if(m == 15)
        return quarter + " " + past + " " + mappina[h];
    else if(m > 1 and m < 30){
        int first = m / 10;
        int second = m % 10;
        return mappina[first * 10] + " " + mappina[second] + " " + minutes + " " + past + " " + mappina[h];
    }

    else if(m == 30)
        return half + " " + past + " " + mappina[h];
    else if(m == 45)
        return quarter + " " + to + " " + mappina[h + 1];
    else
        return mappina[60 - m] + " " + minutes + " " + to + " " + mappina[h + 1];
}




int main() {
    cout << timeInWords(6, 35);
    return 0;
}