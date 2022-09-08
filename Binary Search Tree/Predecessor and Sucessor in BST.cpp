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

int min(Node *root)
{
    if (root == 0)
        return -1;
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}
int max(Node *root)
{
    if (root == 0)
        return -1;
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    if (root == 0)
        return {0, 0};
    Node *temp = root;
    int s = -1;
    int p = -1;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            s = temp->data;
            temp = temp->left;
        }
        else
        {
            p = temp->data;
            temp = temp->right;
        }
    }
    if (temp->left)
        p = max(temp->left);
    if (temp->right)
        s = min(temp->right);
    return {p, s};
}

int main()
{
    return 0;
}