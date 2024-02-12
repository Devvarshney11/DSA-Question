#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Recursion and Memoization
int solve(int n, vector<vector<int>> &points, vector<vector<int>> &dp,
          int taskPerformed)
{
    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != taskPerformed)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[n][taskPerformed] != -1)
    {
        return dp[n][taskPerformed];
    }
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != taskPerformed)
        {
            int merit = points[n][i] + solve(n - 1, points, dp, i);
            maxi = max(maxi, merit);
        }
    }
    return dp[n][taskPerformed] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, points, dp, 3);
}
// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int merit = points[day][i] + dp[day - 1][i];
                    maxi = max(maxi, merit);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n - 1][3];
}
int main()
{
    return 0;
}