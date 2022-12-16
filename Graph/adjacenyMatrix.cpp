#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class graph
{
public:
    int nodes;
    int edges;
    int adj[5][5] = {0};
    graph(int n, int m)
    {
        nodes = n;
        edges = m;
    }
    void insertEdges(int u, int v, int direction)
    {
        adj[u][v] = 1;
        if (direction == 0)
        {
            adj[v][u] = 1;
        }
    }
    void printAdjacency()
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << "->";
            for (int j = 0; j < nodes; j++)
            {
                if (adj[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int m;
    cin >> m;
    graph g(n, m);
    for (int i = 0; i < m; i++)
    {
        cout << "flag1" << endl;
        int u, v;
        cin >> u >> v;
        g.insertEdges(u, v, 0);
        cout << "Flag2" << endl;
    }
    g.printAdjacency();
    return 0;
}