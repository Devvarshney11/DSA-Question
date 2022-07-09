#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string str)
{
    string res = "";
    stack<char> st;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            res += ch;
        }
        else if(ch == ')')
        {
            st.push(ch);
        }
        else if(ch == '(')
        {
            while(st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            st.top();
        }
        else
        {
            while(!st.empty() && precedence(ch)<precedence(st.top()))
            {
                res+= st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
     string str = "a-b/c*d+e";
    cout<<infixToPrefix(str);
    return 0;
}