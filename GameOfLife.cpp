#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getLiveNeighbours(int i, int j, int n, int m,
                          vector<vector<int>> &board)
    {
        int ln = 0;
        if (i > 0)
        {
            if (board[i - 1][j] == 1 || board[i - 1][j] == 3)
                ln++;
        }
        if (j > 0)
        {
            if (board[i][j - 1] == 1 || board[i][j - 1] == 3)
                ln++;
        }
        if (i < n - 1)
        {
            if (board[i + 1][j] == 1 || board[i + 1][j] == 3)
                ln++;
        }
        if (j < m - 1)
        {
            if (board[i][j + 1] == 1 || board[i][j + 1] == 3)
                ln++;
        }
        if (i > 0 and j > 0)
        {
            if (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3)
                ln++;
        }
        if (i > 0 and j < m - 1)
        {
            if (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3)
                ln++;
        }
        if (i < n - 1 and j > 0)
        {
            if (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3)
                ln++;
        }
        if (i < n - 1 and j < m - 1)
        {
            if (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3)
                ln++;
        }
        return ln;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int ln = getLiveNeighbours(i, j, n, m, board);
                if (board[i][j] == 0)
                {
                    if (ln == 3)
                    {
                        board[i][j] = 2;
                    }
                }
                else if (board[i][j] == 1)
                {
                    if (ln < 2 || ln > 3)
                        board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};