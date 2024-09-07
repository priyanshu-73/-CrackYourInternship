#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int open, int close, string curr, int n, vector<string> &res)
    {
        if (curr.length() == n * 2)
        {
            res.push_back(curr);
            return;
        }

        if (open < n)
            helper(open + 1, close, curr + "(", n, res);
        if (close < open)
            helper(open, close + 1, curr + ")", n, res);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(0, 0, "", n, res);
        return res;
    }
};