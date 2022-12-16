#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class graph
{
public:
    int nodes;
    int edges;
    graph(int n,int m)
    {
        nodes = n;
        edges = m;
    }
    unordered_map<int, vector<int>> mp;

    void insertEdge(int u, int v, int direction)
    {
        mp[u].push_back(v);
        if (direction == 0)
        {
            mp[v].push_back(u);
        }
    }
    void printAdjacency()
    {
        for(auto it : mp)
        {
            cout<<it.first<<"->";
            for(int i = 0;i<it.second.size();i++)
            {
                cout<<it.second[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;
    graph g(n,m);
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.insertEdge(u,v,0);
    }
    g.printAdjacency();
    return 0;
}