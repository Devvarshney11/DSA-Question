#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// By DFS
void dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it,visited,adj,st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int,vector<int>> adj;
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<bool> visited(v);
    for(int i = 0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
//By BFS/Kahn's Algorithm
vector<int> topologicalsort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int,vector<int>> adj;
    vector<int> indegree(v,0);
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for(int i = 0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {   
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it : adj[temp])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}