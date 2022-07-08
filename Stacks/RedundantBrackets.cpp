// Given valid mathematical expressions in the form of a string.
// You are supposed to return true if the given expression contains a pair of redundant brackets,
// else return false.
// The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

// Note :
// A pair of brackets is said to be redundant when a subexpression is
// surrounded by needless/ useless brackets.

// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless.
// While (a + (b*c)) does not have any pair of redundant brackets.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string st = "((a+b))";
    cout<<findRedundantBrackets(st);
    return 0;
}