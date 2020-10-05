// The Grid Problem

#include <bits/stdc++.h>

using namespace std;

int minCost(int grid[][3], int row, int col)
{
    int dp[100][100] = {};

    dp[0][0] = grid[0][0];

    for (int i = 1; i < col; i++)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < row; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int r = 1; r < row; r++)
    {
        for (int c = 1; c < col; c++)
        {
            dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + grid[r][c];
        }
    }

    return dp[row - 1][col - 1];
}

int main()
{
    int grid[3][3] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}};

    cout << minCost(grid, 3, 3);

    return 0;
}
