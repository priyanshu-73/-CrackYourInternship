#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int startRow = 0, startCol = 0;
        int endRow = n - 1, endCol = m - 1;
        int count = 0, total = n * m;
        vector<int> ans;
        while (count < total)
        {
            for (int i = startCol; count < total and i <= endCol; i++)
            {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for (int i = startRow; count < total and i <= endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for (int i = endCol; count < total and i >= startCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for (int i = endRow; count < total and i >= startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};