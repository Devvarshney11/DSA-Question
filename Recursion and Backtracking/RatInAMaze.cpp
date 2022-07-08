// Consider a rat placed at (0, 0) in a square matrix of order N * N.
// It has to reach the destination at (N - 1, N - 1).
// Find all possible paths that the rat can take to reach from source to destination.
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while
// value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.
// If the source cell is 0, the rat cannot move to any other cell.
// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1},
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at
// (3, 3) from (0, 0) by two paths - DRDDRR
// and DDRDRR, when printed in sorted order
// we get DDRDRR DRDDRR.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool isSafe(vector<vector<int>> m, vector<vector<int>> v, int row, int col, int n)
{
    if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1 && v[row][col] == 0)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> m, vector<vector<int>> v, string p, int row, int col, int n, vector<string> &ans)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(p);
        return;
    }
    v[row][col] = 1;
    // right
    if (isSafe(m, v, row, col + 1, n)) // for travelling right we need to increment col
    {
        p.push_back('R');
        solve(m, v, p, row, col + 1, n, ans);
        p.pop_back();
    }
    // left
    if (isSafe(m, v, row, col - 1, n)) // for travelling left we need to decrement col
    {
        p.push_back('L');
        solve(m, v, p, row, col - 1, n, ans);
        p.pop_back();
    }
    // up
    if (isSafe(m, v, row - 1, col, n)) // for travelling up we need to decrement row
    {
        p.push_back('U');
        solve(m, v, p, row - 1, col, n, ans);
        p.pop_back();
    }
    // down
    if (isSafe(m, v, row + 1, col, n)) // for travelling right we need to increment row
    {
        p.push_back('D');
        solve(m, v, p, row + 1, col, n, ans);
        p.pop_back();
    }
}
vector<string> findPath(vector<vector<int>> m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;
    int row = 0;
    int col = 0;
    string path = "";
    vector<vector<int>> v = m;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            v[i][j] = 0;
        }
    }
    solve(m,v,path,row,col,n,ans);
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> m(n,vector<int>(n,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
    vector<string> ans = findPath(m,n);
    sort(ans.begin(),ans.end());
    for(auto it: ans)
    {
        cout<<it<<endl;
    }
    return 0;
}
