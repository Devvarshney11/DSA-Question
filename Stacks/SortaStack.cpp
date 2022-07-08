#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void insertAtRightPlace(stack<int> &st, int x)
{
    if (st.empty() || st.top() < x)
    {
        st.push(x);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtRightPlace(st, x);
    st.push(ele);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int ele = stack.top();
    stack.pop();
    sortStack(stack);
    insertAtRightPlace(stack, ele);
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
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(5);
    st.push(1);
    sortStack(st);
    printStack(st);
    return 0;
}