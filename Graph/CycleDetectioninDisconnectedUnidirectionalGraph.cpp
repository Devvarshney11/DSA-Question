#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#define ump unordered_map

using namespace std;

// By Breadht first search
string solve(int node, ump<int, vector<int>> &adj, ump<int, bool> &visited, ump<int, int> &parent)
{
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto &it : adj[temp])
        {
            if (!visited[it])
            {
                visited[it] = true;
                parent[it] = temp;
                q.push(it);
            }
            else if (visited[it] && it != parent[temp])
            {
                return "Yes";
            }
        }
    }
    return "No";
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    ump<int, vector<int>> adj;
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    ump<int, bool> visited;
    ump<int, int> parent;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            string ans = solve(i, adj, visited, parent);
            if (ans == "Yes")
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// By Depth first search
bool solve(int node, ump<int, vector<int>> &adj, ump<int, bool> &visited, int parent)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            bool temp = solve(it, adj, visited, node);
            if (temp == true)
                return true;
        }
        else if (visited[it] && it != parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    ump<int, vector<int>> adj;
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    ump<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = solve(i, adj, visited, -1);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    return 0;
}