#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

vector<pair<pair<int, int>, int>> primsAlgo(vector < pair<pair<int, int>, int>> & edges, int v, int e)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(v,INT_MAX);
    vector<bool> mst(v,false);
    vector<int> parent(v,-1);
    key[0] = 0;
    parent[0] = -1;
    for(int i = 0;i<v;i++)
    {
        int mini = INT_MAX;
        int u;
        for(int j = 0;j<v;j++)
        {
            if(!mst[j] && mini>key[j])
            {
                mini = key[j];
                u = j;
            }
        }
        mst[u] = true;
        for(auto it : adj[u])
        {
            if(it.second < key[it.first])
            {
                key[it.first] = it.second;
                parent[it.first] = u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 1;i<v;i++)
    {
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
int main()
{
    return 0;
}
