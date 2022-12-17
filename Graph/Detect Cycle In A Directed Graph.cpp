#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// By DFS
bool dfs(int n, unordered_map<int, bool> &dfsvisited, unordered_map<int, bool> &v, unordered_map<int, vector<int>> &adj)
{
    dfsvisited[n] = true;
    v[n] = true;

    for (auto it : adj[n])
    {
        if (!v[it])
        {
            bool isconnected = dfs(it, dfsvisited, v, adj);
            if (isconnected)
                return true;
        }
        else if (dfsvisited[it])
        {
            return true;
        }
    }
    dfsvisited[n] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, bool> dfsvisited;
    unordered_map<int, bool> v;
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            bool isconnected = dfs(i, dfsvisited, v, adj);
            if (isconnected)
                return true;
        }
    }
    return false;
}
// By BFS/Kahn's Algorithm
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(n, 0);
    for (auto it : edges)
    {
        adj[it.first - 1].push_back(it.second - 1);
        indegree[it.second - 1]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;
        for (auto it : adj[temp])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return (count != n);
}
int main()
{
    return 0;
}