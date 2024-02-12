#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int solve(int i, int j1, int j2, int &r, int &c, vector<vector<int>> &grid,
          vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
    {
        return -1e8;
    }
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e8;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int value;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += solve(i + 1, j1 + d1, j2 + d2, r, c, grid, dp);
            maxi = max(value, maxi);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, n, m, grid, dp);
}

int main()
{
    return 0;
}