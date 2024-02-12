#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
// Recursion
int solve(int n, vector<int> &nums)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;
    int notPick = solve(n - 1, nums);
    int pick = nums[n] + solve(n - 2, nums);
    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size() - 1;
    return solve(n, nums);
}
// Memoization
int solve(int n, vector<int> &nums, vector<int> &dp)
{
    if (n == 0)
        return dp[0] = nums[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int notPick = solve(n - 1, nums, dp);
    int pick = nums[n] + solve(n - 2, nums, dp);
    return dp[n] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}
// Tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int notPick = dp[i - 1];
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}
// Space Optimization
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int a = 0;
    int b = nums[0];
    for (int i = 1; i < n; i++)
    {
        int notPick = b;
        int pick = nums[i];
        if (i > 1)
            pick += a;
        a = b;
        b = max(pick, notPick);
    }
    return b;
}
int main()
{
    return 0;
}