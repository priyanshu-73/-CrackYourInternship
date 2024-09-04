#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int res = INT_MIN;
        for (auto point : points)
        {
            while (pq.size() && point[0] - pq.top().second > k)
                pq.pop();
            if (!pq.empty())
            {
                res = max(res, point[0] + point[1] + pq.top().first);
            }
            pq.push({point[1] - point[0], point[0]});
        }
        return res;
    }
};