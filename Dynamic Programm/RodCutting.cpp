#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// Recurrsion and Memoization
int solve(int l, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (l == 1)
    {
        return price[0] * n;
    }
    if (dp[l - 1][n] != -1)
        return dp[l - 1][n];
    int notTake = solve(l - 1, n, price, dp);
    int take = INT_MIN;
    if (l <= n)
    {
        take = price[l - 1] + solve(l, n - l, price, dp);
    }
    return dp[l - 1][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n, n, price, dp);
}

// Tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        int rodLength = i + 1;
        for (int j = 0; j <= n; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (rodLength <= j)
                take = price[i] + dp[i][j - rodLength];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
// Space Optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        price[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        int rodLength = i + 1;
        for (int j = 0; j <= n; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (rodLength <= j)
                take = price[i] + prev[j - rodLength];
            prev[j] = max(take, notTake);
        }
    }
    return prev[n];
}
F int main()
{
    return 0;
}