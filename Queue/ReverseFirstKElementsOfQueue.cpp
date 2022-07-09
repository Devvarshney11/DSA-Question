#include <bits/stdc++.h>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    // step 1 : pop first k element from queue and push into stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // step 2 : fetch element from stack and put in queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    // step 3 : fetch n-k element from queue and push back in queue
    int n = q.size();
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    while (n-- > 0)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    queue<int> ans = modifyQueue(q, k);
    while (!ans.empty())
    {
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
}
