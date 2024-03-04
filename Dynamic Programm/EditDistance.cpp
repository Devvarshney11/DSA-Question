#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Recursion and Memoization
int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (j == 0)
        return i;
    if (i == 0)
        return j;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i - 1] == word2[j - 1])
    {
        return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
    }
    return dp[i][j] = min(solve(i - 1, j, word1, word2, dp), min(solve(i, j - 1, word1, word2, dp), solve(i - 1, j - 1, word1, word2, dp))) + 1;
}
int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, word1, word2, dp);
}

// Tabulation
int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    return 0;
}