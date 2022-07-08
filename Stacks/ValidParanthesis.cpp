#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> st;
    int i = 0;
    while (expression[i] != '\0')
    {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else if (ch == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
                return false;
        }
        else if (ch == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
                return false;
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
                return false;
        }
        i++;
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string st = "{{{{{}}}}}";
    cout << isValidParenthesis(st);
    return 0;
}