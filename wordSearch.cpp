#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool search(int i, int j, int k, int n, int m, vector<vector<char>> &board, string word)
    {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
            return false;

        board[i][j] = '#';
        bool op1 = search(i + 1, j, k + 1, n, m, board, word);
        bool op2 = search(i - 1, j, k + 1, n, m, board, word);
        bool op3 = search(i, j + 1, k + 1, n, m, board, word);
        bool op4 = search(i, j - 1, k + 1, n, m, board, word);
        board[i][j] = word[k];

        return op1 || op2 || op3 || op4;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (search(i, j, 0, n, m, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};