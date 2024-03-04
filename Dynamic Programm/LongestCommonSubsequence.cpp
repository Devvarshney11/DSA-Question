#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Recursion and Memoization
int solve(int i1, int i2, string &s, string &t, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (s[i1] == t[i2])
        return dp[i1][i2] = 1 + solve(i1 - 1, i2 - 1, s, t, dp);
    return dp[i1][i2] = max(solve(i1 - 1, i2, s, t, dp), solve(i1, i2 - 1, s, t, dp));
}
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, s, t, dp);
}

// Tabulation
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
// Space Optimization
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    return 0;
}