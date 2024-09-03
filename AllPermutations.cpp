#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int curr, int n, vector<int> &arr, set<vector<int>> &s)
    {
        if (curr >= n)
            s.insert(arr);

        for (int i = curr; i < n; i++)
        {
            swap(arr[curr], arr[i]);
            helper(curr + 1, n, arr, s);
            swap(arr[curr], arr[i]);
        }
    }

public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        set<vector<int>> s;
        vector<vector<int>> res;
        helper(0, n, arr, s);
        for (auto i : s)
        {
            res.push_back(i);
        }
        return res;
    }
};