#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
#define ump unordered_map

void createAdjacenyList(vector<pair<int, int>> &edges, ump<int, vector<int>> &mp)
{
    for (auto it : edges)
    {
        mp[it.first].push_back(it.second);
        mp[it.second].push_back(it.first);
    }
}
void bfs(int node, ump<int, vector<int>> &mp, ump<int, bool> &visit, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visit[node] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto it : mp[temp])
        {
            if (!visit[it])
            {
                q.push(it);
                visit[it] = 1;
            }
        }
    }
}
vector<int> BFS(int nodes, vector<pair<int, int>> &edges)
{
    ump<int, vector<int>> mp;
    createAdjacenyList(edges, mp);
    vector<int> ans;
    ump<int, bool> visit;
    for (int i = 0; i < nodes; i++)
    {
        if (!visit[i])
        {
            bfs(i, mp, visit, ans);
        }
    }
    return ans;
}
int main()
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int m;
    cin >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first;
        cin >> edges[i].second;
    }
    vector<int> ans = BFS(n, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}