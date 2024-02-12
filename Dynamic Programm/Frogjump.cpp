#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
// Recursion && Memoization
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return dp[n] = 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}

// Tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
// Space optimization
int frogJump(int n, vector<int> &heights)
{
    int a = 0;
    int b = 0;
    for (int i = 1; i < n; i++)
    {
        int left = b + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = a + abs(heights[i] - heights[i - 2]);
        a = b;
        b = min(left, right);
    }
    return b;
}
int main()
{
    return 0;
}