#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Recursion && Memoization
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = i > 0 ? grid[i][j] + solve(i - 1, j, grid, dp) : INT_MAX;
    int up = j > 0 ? grid[i][j] + solve(i, j - 1, grid, dp) : INT_MAX;
    return dp[i][j] = min(left, up);
}
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
}

// Tabulation
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int left = i > 0 ? grid[i][j] + solve(i - 1, j, grid, dp) : INT_MAX;
                int up = j > 0 ? grid[i][j] + solve(i, j - 1, grid, dp) : INT_MAX;
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n - 1][m - 1];
}
// Space Optimization

int main()
{
    return 0;
}