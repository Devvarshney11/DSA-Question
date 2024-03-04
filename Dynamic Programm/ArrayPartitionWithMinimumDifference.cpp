#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    //  int n = arr.size();
    int totalSum = 0;
    for (auto &it : arr)
    {
        totalSum += it;
    }
    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
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
    int mini = 1e9;
    for (int i = 0; i <= totalSum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            mini = min(mini, abs((totalSum - i) - i));
        }
    }
    return mini;
}

int main()
{
    return 0;
}