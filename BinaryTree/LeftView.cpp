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

vector<int> leftView(Node *root)
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
        int lvl = temp.second;

        if (!mp[lvl])
            mp[lvl] = node->data;

        if (node->left)
            q.push(make_pair(node->left, lvl + 1));
        if (node->right)
            q.push(make_pair(node->right, lvl + 1));
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//By Recursion
void solve(Node *root,int level,vector<int> &ans)
{
    if (root == 0)
    {
        return;
    }
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left,level+1,ans);
    solve(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root == 0)
        return ans;
    
    solve(root,0,ans);
    return ans;
}
int main()
{
    return 0;
}