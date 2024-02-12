#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto it : vec)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    set<pair<int, int>> s;
    vector<int> dist(vertices, INT_MAX);
    s.insert({0, source});
    dist[source] = 0;
    while (s.size() != 0)
    {
        auto top = *(s.begin());
        int node = top.second;
        int distance = top.first;
        for (auto it : adj[top.second])
        {
            if (distance + it.second < dist[it.first])
            {
                auto temp = s.find({dist[it.first], it.first});
                if (temp != s.end())
                {
                    s.erase(temp);
                }
                dist[it.first] = distance + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    return dist;
}
// By Queue
vector<int> dijkstrasAlgo(int &nodes, vector<vector<int>> &edges, int source)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    queue<pair<int, int>> q;
    ;
    vector<int> path(nodes, INT_MAX);
    q.push({0, source});
    path[source] = 0;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int distance = temp.first;
        int node = temp.second;
        for (auto &it : adj[node])
        {
            if (path[it.first] > it.second + distance)
            {
                path[it.first] = it.second + distance;
                q.push({path[it.first], it.first});
            }
        }
    }
    return path;
}
int main()
{
    return 0;
}