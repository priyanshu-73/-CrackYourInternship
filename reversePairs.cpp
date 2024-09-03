#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(int low, int mid, int high, vector<int> &nums, int &ans)
    {
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high and nums[i] > 2 * (long long)nums[j])
                j++;
            ans += j - (mid + 1);
        }
        int left = low, right = mid + 1;
        j = 0;
        int size = high - low + 1;
        vector<int> temp(size, 0);
        while (left <= mid and right <= high)
        {
            if (nums[left] < nums[right])
                temp[j++] = nums[left++];
            else
                temp[j++] = nums[right++];
        }

        while (left <= mid)
            temp[j++] = nums[left++];
        while (right <= high)
            temp[j++] = nums[right++];

        j = 0;
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[j++];
        }
    }

    void mergeSort(int low, int high, vector<int> &nums, int &ans)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(low, mid, nums, ans);
        mergeSort(mid + 1, high, nums, ans);
        merge(low, mid, high, nums, ans);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int ans = 0;
        mergeSort(0, nums.size() - 1, nums, ans);
        return ans;
    }
};