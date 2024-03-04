#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Recursion and Memoization
int solve(int i, int a, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (a % coins[0] == 0)
            return a / coins[0];
        return 1e8;
    }
    if (dp[i][a] != -1)
        return dp[i][a];
    int nottake = 0 + solve(i - 1, a, coins, dp);
    int take = 10e8;
    if (coins[i] <= a)
        take = 1 + solve(i, a - coins[i], coins, dp);
    return dp[i][a] = min(nottake, take);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = solve(n - 1, amount, coins, dp);
    return ans == 1e8 ? -1 : ans;
}
// Tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e8;
    }
    for (int i = 1; i < n; i++)
    {
        for (int a = 0; a <= amount; a++)
        {
            int nottake = 0 + dp[i - 1][a];
            int take = 10e8;
            if (coins[i] <= a)
                take = 1 + dp[i][a - coins[i]];
            dp[i][a] = min(nottake, take);
        }
    }
    int ans = dp[n - 1][amount];
    return ans == 1e8 ? -1 : ans;
}
// Space Optimization

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e8;
    }
    for (int i = 1; i < n; i++)
    {
        for (int a = 0; a <= amount; a++)
        {
            int nottake = prev[a];
            int take = 10e8;
            if (coins[i] <= a)
                take = 1 + curr[a - coins[i]];
            curr[a] = min(nottake, take);
        }
        prev = curr;
    }
    int ans = curr[amount];
    return ans == 1e8 ? -1 : ans;
}
int main()
{
    return 0;
}