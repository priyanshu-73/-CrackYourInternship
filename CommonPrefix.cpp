#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string ans = "";
        for (int i = 0; i < strs[strs.size() - 1].length(); i++)
        {
            if (strs[0][i] != strs[strs.size() - 1][i])
                break;
            ans += strs[strs.size() - 1][i];
        }
        return ans;
    }
};