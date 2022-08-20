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

Node *lca(Node *root, int n1, int n2)
{
    if (root == 0)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (!left && !right)
        return nullptr;

    if (!left)
        return right;
    if (!right)
        return left;
    return root;
}