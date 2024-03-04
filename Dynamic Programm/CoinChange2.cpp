#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solve(int idx, int target, int *arr, vector<vector<long long>> &dp)
{
    if (idx == 0)
    {
        return (target % arr[0] == 0);
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];
    long long notPick = solve(idx - 1, target, arr, dp);
    long long pick = 0;
    if (arr[idx] <= target)
    {
        pick = solve(idx, target - arr[idx], arr, dp);
    }
    return dp[idx][target] = notPick + pick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long long>> dp(n, vector<long long>(value + 1, -1));
    return solve(n - 1, value, denominations, dp);
}
// Tabulation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long long>> dp(n, vector<long long>(value + 1, 0));
    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % denominations[0] == 0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= value; T++)
        {
            long long notPick = dp[i - 1][T];
            long long pick = 0;
            if (denominations[i] <= T)
            {
                pick = dp[i][T - denominations[i]];
            }
            dp[i][T] = notPick + pick;
        }
    }
    return dp[n - 1][value];
}
// Space Optimize it by using two rows prev and curr

int main()
{
    return 0;
}