#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    void createAdjList(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }
    void dfs(int node, vector<bool> &visited, stack<int> &st)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it.first])
            {
                dfs(it.first, visited, st);
            }
        }
        st.push(node);
    }
    void shortestPath(vector<int> &path, stack<int> &st,int s)
    {
        
        path[s] = 0;
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            if(path[t] != INT_MAX)
            {
                for(auto it : adj[t])
                {
                    if(path[t] + it.second < path[it.first])
                    {
                        path[it.first] = path[t] + it.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.createAdjList(0, 1, 5);
    g.createAdjList(0, 2, 3);
    g.createAdjList(1, 3, 6);
    g.createAdjList(1, 2, 2);
    g.createAdjList(2, 3, 7);
    g.createAdjList(3, 4, -1);
    g.createAdjList(2, 4, 4);
    g.createAdjList(2, 5, 2);
    g.createAdjList(4, 5, -2);

    // Topological Sort
    vector<bool> visited(6, 0);
    stack<int> st;
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, st);
        }
    }
    vector<int> path(6, INT_MAX);
    g.shortestPath(path,st,1);
    for(int i = 0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    return 0;
}