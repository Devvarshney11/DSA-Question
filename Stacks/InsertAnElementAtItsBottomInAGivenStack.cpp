#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(ele);
}

void printStack(stack<int> st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    printStack(st);
    cout << ele << " ";
    st.push(ele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    insertAtBottom(st,0);
    printStack(st);
    return 0;
}