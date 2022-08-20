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

Node *build(int *in, int *pre, int &index, int start, int end, int n , unordered_map<int,int> &mp)
{
    if (index >= n || start > end)
    {
        return 0;
    }
    Node *root = new Node(pre[index++]);
    int pos = mp[root->data];

    root->left = build(in, pre, index, start, pos - 1, n ,mp);
    root->right = build(in, pre, index, pos + 1, end, n , mp);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int index = 0;
    unordered_map<int,int> mp;   //Map for index with element in inorder;
    for(int i = 0;i<n;i++)
    {
        mp[in[i]] = i;
    }
    return build(in, pre, index, 0, n - 1, n,mp);
}
int main()
{
    return 0;
}