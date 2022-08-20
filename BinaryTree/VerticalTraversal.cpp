#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q;

    vector<int> ans;
    if (root == 0)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        mp[hd][lvl].push_back(frontnode->data);
        if (frontnode->left)
            q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
        if (frontnode->right)
            q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto it : mp)
    {
        for (auto i : it.second)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}