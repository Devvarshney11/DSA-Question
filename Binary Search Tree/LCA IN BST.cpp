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

// By Iteration
Node *LCAinaBST(Node *root, Node *a, Node *b)
{
    while (root)
    {
        if (root->data > a->data && root->data > b->data)
            root = root->left;
        else if (root->data < a->data && root->data < b->data)
            root = root->right;
        else
            break;
    }
    return root;
}
//By recursion
Node *LCAinaBST(Node *root, Node *a, Node *b)
{
    if (root == 0)
        return 0;
    if (root->data > a->data && root->data > b->data)
        return LCAinaBST(root->left, a, b);
    else if (root->data < a->data && root->data < b->data)
        return LCAinaBST(root->right, a, b);
    return root;
}
int main()
{
    return 0;
}