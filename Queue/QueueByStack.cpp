#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class queue
{
    stack<int> st;
    
    void insertAtBottom(stack<int> &s, int data)
    {
        if(s.empty())
        {
            s.push(data);
            return;
        }
        int ele = s.top();
        s.pop();
        insertAtBottom(s,data);
        s.push(ele);
    }
public:
    void enqueue(int data)
    {
         if(st.empty())
         {
            st.push(data);
         }
         else
         {
            insertAtBottom(st,data);
         }
    }
    void dequeue()
    {
        if(st.empty())
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        else
        {
            st.pop();
        }
    }
    int getFront()
    {
        return st.top();
    }
    
    bool empty()
    {
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}