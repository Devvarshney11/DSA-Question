#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
// Recursion and Memoization
int solve(int i, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (weight[0] <= w)
            return value[0];
        return 0;
    }
    if (dp[i][w] != -1)
        return dp[i][w];
    int notTake = 0 + solve(i - 1, w, weight, value, dp);
    int take = INT_MIN;
    if (weight[i] <= w)
        take = value[i] + solve(i - 1, w - weight[i], weight, value, dp);
    return dp[i][w] = max(notTake, take);
}
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(n - 1, maxWeight, weight, value, dp);
}
// Tabulation
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + dp[i - 1][w];
            int take = INT_MIN;
            if (weight[i] <= w)
                take = value[i] + dp[i - 1][w - weight[i]];
            dp[i][w] = max(notTake, take);
        }
    }
    return dp[n - 1][maxWeight];
}

// Space Optimization
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (weight[i] <= w)
                take = value[i] + prev[w - weight[i]];
            curr[w] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// From double rows to single row
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (weight[i] <= w)
                take = value[i] + prev[w - weight[i]];
            prev[w] = max(notTake, take);
        }
    }
    return prev[maxWeight];
}

int main()
{
    return 0;
}