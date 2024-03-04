#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int lcs(string &str1, string &str2)
{
    int n = str1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][n];
}
int minimumInsertions(string &s)
{
    int n = s.length();
    string t = "";
    for (int i = n - 1; i >= 0; i--)
    {
        t += s[i];
    }
    return n - lcs(s, t);
}

int main()
{
    return 0;
}