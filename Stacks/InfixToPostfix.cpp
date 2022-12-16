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
string infixToPostFix(string str)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if((ch >= 'a' && ch <= 'z' )||(ch >='A' && ch <= 'Z') || (ch >='0' && ch<='9'))
        {
            res += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            while(st.top() != '(')
            {
                res += st.top();    
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(ch)<=precedence(st.top()))
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
    return res;
}
int main()
{
    string str = "A*(B+C*(D+E))/(F*(G+H))";
    cout<<infixToPostFix(str);
    return 0;
}