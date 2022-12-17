#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int node,unordered_map<int,vector<int>> &adj,vector<int> &cmp,unordered_map<int,bool> &visited)
{
    cmp.push_back(node);
    visited[node] = true;
    for(auto it : adj[node])
    {
        dfs(it,adj,cmp,visited);
    }
}
vector<vector<int>> depthFirstSearch(int n, int m,vector<pair<int,int>> &edges)
{
    unordered_map<int,vector<int>> adj;
    for(auto it : edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,adj,component,visited);
            ans.push_back(component);
        }
    }
    return ans;
} 
int main()
{
    return 0;
}