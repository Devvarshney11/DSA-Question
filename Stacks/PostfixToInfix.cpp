#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return true;
    }
    return false;
}
string postfixToInfix(string str)
{
    string res = "";
    stack<string> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isOperator(ch))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            res = '(' + op2 + ch + op1 + ')';
            st.push(res);
        }
        else
        {
            st.push(string(1, ch));
        }
    }
    res = st.top();
    st.pop();
    return res;
}

int main()
{
    string str = "abc/d*-e+";
    cout<<postfixToInfix(str);
    return 0;
}