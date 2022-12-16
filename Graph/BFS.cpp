#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>

#define ump unordered_map
using namespace std;

void createAdjacenyList(vector<pair<int, int>> &edges, ump<int, vector<int>> &mp)
{
    for (auto it : edges)
    {
        mp[it.first].push_back(it.second);
        mp[it.second].push_back(it.first);
    }
}
void bfs(int node,ump<int, vector<int>> &mp,ump<int,bool> &visit,vector<int> ans)
{
    queue<int> q;
    q.push(node);
    visit[node] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it : mp[temp])
        {
            if(!visit[it])
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
    ump<int,bool> visit;
    for(int i = 0;i<nodes;i++)
    {
        if(!visit[i])
        {
            bfs(i,mp,visit,ans);
        }
    }
    return ans;
}
int main()
{
    return 0;
}