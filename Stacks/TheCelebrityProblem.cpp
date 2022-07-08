// A celebrity is a person who is known to all but does not know anyone at a party.
// If you go to a party of N people, find if there is a celebrity in the party or not.

// A square NxN matrix M[][] is used to represent people at the party such that
// if an element of row i and column j  is set to 1 it means ith person knows jth person.
// Here M[i][i] will always be 0.

// Note: Follow 0 based indexing.

// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0},
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // step1: intialize stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // step2: Get that one element which knows no one
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (M[a][b] == 1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int celeb = st.top();

    // step3: verify row

    bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[celeb][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // step4: verify col

    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][celeb] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true)
    {
        return celeb;
    }
    return -1;
}

int main()
{
    vector<vector<int>>M(3,vector<int>(3)); 
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cin>>M[i][j];
        }
    }
    cout<<celebrity(M,3);                  
    return 0;
}