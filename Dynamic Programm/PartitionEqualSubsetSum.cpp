#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

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
bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (auto &it : nums)
    {
        totalSum += it;
    }
    if (totalSum % 2 != 0)
    {
        return false;
    }
    return subsetSumToK(nums.size(), totalSum / 2, nums);
}
// Space Optimization
bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for (auto &it : nums)
    {
        totalSum += it;
    }
    // int totalSum = accumulate(begin(nums), end(nums), 0);
    if (totalSum % 2 != 0)
    {
        return false;
    }
    int halfSum = totalSum / 2;
    vector<bool> dp(halfSum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = halfSum; j >= nums[i]; j--)
        {
            if (dp[j - nums[i]])
                dp[j] = true;
        }
    }
    return dp[halfSum];
}
int main()
{
    return 0;
}