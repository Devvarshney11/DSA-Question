#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Memoization
bool isPalindrome(string &s, int start, int end, vector<vector<bool>> &dp)
{
    if (start > end)
        return true;
    if (dp[start][end])
        return dp[start][end];
    if (s[start] == s[end])
        return dp[start][end] = isPalindrome(s, start + 1, end - 1, dp);
    return dp[start][end] = false;
}
int countSubstrings(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j, dp))
                count++;
        }
    }
    return count;
}
// Tabulation
int countSubstrings(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            if (i == j)
            {
                dp[i][j] = true;
            }
            else if (i + 1 == j)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
            if (dp[i][j])
                count++;
        }
    }
    return count;
}
int main()
{
    return 0;
}