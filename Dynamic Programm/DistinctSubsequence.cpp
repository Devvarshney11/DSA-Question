#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// Recursion and Memoization
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
    }
    return dp[i][j] = solve(i - 1, j, s, t, dp);
}
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, s, t, dp);
}
// Tabulation
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
// Space Optimization
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<int> prev(m + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j > 0; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                prev[j] = prev[j - 1] + prev[j];
            }
            else
                prev[j] = prev[j];
        }
    }
    return prev[m];
}
int main()
{
    return 0;
}