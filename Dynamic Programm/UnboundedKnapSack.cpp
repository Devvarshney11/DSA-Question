#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// Memoization
int solve(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (i == 0)
        return (profit[0] * (w / weight[0]));
    if (dp[i][w] != -1)
        return dp[i][w];
    int notTake = solve(i - 1, w, profit, weight, dp);
    int take = INT_MIN;
    if (weight[i] <= w)
    {
        take = profit[i] + solve(i, w - weight[i], profit, weight, dp);
    }
    return dp[i][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}
// Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = profit[0] * (i / weight[0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}
// Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1), curr(w + 1);
    for (int i = 0; i <= w; i++)
    {
        prev[i] = profit[0] * (i / weight[0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = profit[i] + curr[j - weight[i]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}
// Space Optimize by one array
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1);
    for (int i = 0; i <= w; i++)
    {
        prev[i] = profit[0] * (i / weight[0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = profit[i] + prev[j - weight[i]];
            }
            prev[j] = max(take, notTake);
        }
    }
    return prev[w];
}
int main()
{
    return 0;
}