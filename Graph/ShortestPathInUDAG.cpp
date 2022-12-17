#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, vector<int>> adj;
    for (auto &it : edges)
    {
        adj[it.second].push_back(it.first);
        adj[it.first].push_back(it.second);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto it : adj[temp])
        {
            if (!visited[it])
            {
                visited[it] = true;
                parent[it] = temp;
                q.push(it);
            }
        }
    }
    int currnode = t;
    vector<int> ans;
    ans.push_back(t);
    while (currnode != s)
    {
        currnode = parent[currnode];
        ans.push_back(currnode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}