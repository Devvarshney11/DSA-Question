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

unordered_map<int, int> mp;
Node *build(int *in, int *post, int &index, int start, int end, int n)
{
    if (index < 0 || start > end)
    {
        return 0;
    }
    Node *root = new Node(post[index--]);
    int pos = mp[root->data];

    root->right = build(in, post, index, pos + 1, end, n);
    root->left = build(in, post, index, start, pos - 1, n);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    int index = n - 1;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    return build(in, post, index, 0, n - 1, n);
}

int main()
{
    return 0;
}