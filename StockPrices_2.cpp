#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = INT_MAX, profit = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
            else{
                profit += nums[i] - mini;
                mini = nums[i];
            }
        }
        return profit;
    }
};