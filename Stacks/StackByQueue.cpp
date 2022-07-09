#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;
class stack
{ 
    queue<int> q;
    void insertAtfront(queue<int> &qu,int x)
    {
          if(qu.empty())
          {
             qu.push(x);
             return;
          }
          int ele = qu.front();
          insertAtfront(qu,x);
          qu.push(ele);
    }
    public:
    void push(int x)
    {
        if(q.empty())
        {
           q.push(x);
        }
        else
        {
            insertAtfront(q,x);
        }
    }
    void pop()
    {
        if(q.empty())
        {
            cout<<"Stack underflow"<<endl;
            return;
        }
        else
        {
            q.pop();
        }
    }
    int top()
    {
        if(q.empty())
        {
            return -1;
        }
        return q.front();
    }
    bool empty()
    {
        if(q.empty())
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