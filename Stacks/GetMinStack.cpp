#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
class MinStack
{
private:
    stack<int> st;
    int mini;

public:
    void push(int data)
    {
        if(st.empty())
        {
            st.push(data);
            mini = data;
        }
        else
        {
            if(data<mini)
            {
                st.push(2*data - mini);
                mini = data;
            }
            else
            {
                st.push(data);
            }
        }
    }
    int pop()
    {
        if(st.empty())
        {
            cout<<"Stack overflow"<<endl;
            return -1;
        }
        else
        {
            if(st.top()<mini)
            {
                int prev = mini;
                mini = 2*mini-st.top();
                st.pop();
                return prev;
            }
            else
            {
                int val = st.top();
                st.pop();
                return val;
            }
        }
    }
    int top()
    {
        if(st.top() < mini)
        {
            return mini;
        }
        else
        {
            return st.top();
        }
    }
    int getMin()
    {
        if(st.empty())
        {
            return -1;
        }
        else
        {
            return mini;
        }
    }
};
int main()
{
    MinStack m;
    m.push(5);
    m.push(3);
    m.push(8);
    cout<<m.getMin();
    m.push(2);
    cout<<endl<<m.getMin();
    cout<<m.pop();
    return 0;

}