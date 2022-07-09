#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    else
    {
        int ele = q.front();
        q.pop();
        reverse(q);
        q.push(ele);
    }
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q = rev(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}