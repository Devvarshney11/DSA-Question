// Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid
// if all the brackets are balanced. Formally for each opening bracket,
// there must be a closing bracket right to it.
// For Example:
// “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
// Ninja wants to make ‘STR’ valid by performing some operations on it.
// In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such
// operation is 1.
// Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

// Note:
// Return -1 if it is impossible to make ‘STR’ valid.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int findMinimumCost(string str)
{
    if (str.length() & 1)
    {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
    int a = 0;
    int b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }
    int ans = ((a + 1) >> 1) + ((b + 1) >> 1);
    return ans;
}

int main()
{
    string st = "{{{}";
    cout<<findMinimumCost(st);
    return 0;
}