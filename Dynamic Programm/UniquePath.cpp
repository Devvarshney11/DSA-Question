#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// Recursion
int solve(int i, int j, int &m, int &n)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    int right = 0;
    if (i + 1 < m)
        right = solve(i + 1, j, m, n);
    int down = 0;
    if (j + 1 < n)
        down = solve(i, j + 1, m, n);
    return right + down;
}

int uniquePaths(int m, int n)
{
    return solve(0, 0, m, n);
}

// Memoization
int solve(int i, int j, int &m, int &n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
        return dp[i][j] = 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = 0;
    if (i + 1 < m)
        right = solve(i + 1, j, m, n, dp);
    int down = 0;
    if (j + 1 < n)
        down = solve(i, j + 1, m, n, dp);
    return dp[i][j] = right + down;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp);
}
// Tabulation
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
// Space Optimization
int uniquePaths(int m, int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                temp[j] = dp[j];
                if (j > 0)
                    temp[j] += temp[j - 1];
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}
int main()
{
    return 0;
}