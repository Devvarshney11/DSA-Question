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
vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == 0)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *node = temp.first;
        int hd = temp.second;

        mp[hd] = node->data;

        if (node->left)
            q.push(make_pair(node->left, hd - 1));
        if (node->right)
            q.push(make_pair(node->right, hd + 1));
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    return 0;
}