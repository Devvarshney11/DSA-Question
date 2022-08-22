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

Node *min(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *max(Node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    return 0;
}