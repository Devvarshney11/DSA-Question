// Given a binary matrix M of size n X m.
// Find the maximum area of a rectangle formed only of 1s in the given matrix.

// Example 1:

// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

#define MAX 1000
using namespace std;
vector<int> nextSmallElement(int *heights, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && heights[i] <= heights[st.top()])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallElement(int *heights, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && heights[i] <= heights[st.top()])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestArea(int *heights, int n)
{
    vector<int> next = nextSmallElement(heights, n);
    vector<int> prev = prevSmallElement(heights, n);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxArea(int M[MAX][MAX], int n, int m)
{
    int area = largestArea(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        area = max(largestArea(M[i], m), area);
    }
    return area;
}
int main()
{
    return 0;
}