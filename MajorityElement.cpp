#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                el = nums[i];
                count = 1;
            }
            else if (el == nums[i])
                count++;
            else
                count--;
        }

        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (el == nums[i])
                count++;
        }
        if (count > n / 2)
            return el;
        return -1;
    }
};