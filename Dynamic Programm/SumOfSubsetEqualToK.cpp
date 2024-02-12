#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Recursion and Memoization
bool solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return (arr[0] == target);
    if (dp[i][target] != -1)
        return dp[i][target];
    bool notTake = solve(i - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[i])
    {
        take = solve(i - 1, target - arr[i], arr, dp);
    }
    return dp[i][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i])
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}
// Space Optimization
int main()
{
    return 0;
}