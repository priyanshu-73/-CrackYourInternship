#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int minJump = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            minJump++;
            if (nums[i] >= minJump)
            {
                minJump = 0;
            }
        }
        if (minJump == 0)
            return true;
        else
            return false;
    }
};