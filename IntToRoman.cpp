#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV",
                         "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL",
                         "L", "LX", "LXX", "LXXX", "XC"};
        string hunds[] = {"", "C", "CC", "CCC", "CD",
                          "D", "DC", "DCC", "DCCC", "CM"};
        string thds[] = {"", "M", "MM", "MMM"};

        return thds[num / 1000] + hunds[(num % 1000) / 100] +
               tens[(num % 100) / 10] + ones[(num % 10)];
    }
};