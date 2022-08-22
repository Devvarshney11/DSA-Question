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

Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    return search(root->right, key);
}

// By iteration

Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    while (root)
    {
        if (root->data == key)
            return root;
        if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}
int main()
{
    return 0;
}