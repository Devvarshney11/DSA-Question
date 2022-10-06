#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    int row;
    int col;
    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return (a->data > b->data);
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        pq.push(temp);
    }
    vector<int> ans;
    while (pq.size() > 0)
    {
        node *temp = pq.top();
        pq.pop();
        ans.push_back(temp->data);
        int row = temp->row;
        int col = temp->col;
        if (col + 1 < kArrays[row].size())
        {
            node *n = new node({kArrays[row][col + 1], row, col + 1});
            pq.push(n);
        }
    }
    return ans;
}

int main()
{
    return 0;
}