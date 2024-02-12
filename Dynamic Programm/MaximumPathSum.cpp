#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Recursion and Memoization
int Traversal(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp, int &m)
{
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + Traversal(i - 1, j, matrix, dp, m);
    int leftUp = -1e8;
    if (j + 1 < m)
        leftUp = matrix[i][j] + Traversal(i - 1, j + 1, matrix, dp, m);
    int RightUp = -1e8;
    if (j > 0)
        RightUp = matrix[i][j] + Traversal(i - 1, j - 1, matrix, dp, m);
    return dp[i][j] = max(up, max(RightUp, leftUp));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, Traversal(n - 1, i, matrix, dp, m));
    }
    return maxi;
}
// Tabulation
int getMaxPathSum(vector<vector<int>> &ma)
{
    int n = ma.size();

    int m = ma[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
        dp[0][i] = ma[0][i];

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            dp[i][j] = dp[i - 1][j];

            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);

            if (j + 1 < m)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);

            dp[i][j] += ma[i][j];
        }
    }

    int ans = -1e9;

    for (int i = 0; i < m; i++)
        ans = max(ans, dp[n - 1][i]);

    return ans;
}
int main()
{
    return 0;
}