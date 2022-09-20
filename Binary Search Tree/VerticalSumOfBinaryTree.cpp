#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

vector<int> verticalSum(Node *root)
{
    vector<int> ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        Node *front = temp.first;
        int hd = temp.second;
        mp[hd] += front->data;
        if(front->left)
        {
            q.push({root->left,hd-1});
        }
        if(front->right)
        {
            q.push({root->right,hd+1});
        }
    }
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    return 0;
}