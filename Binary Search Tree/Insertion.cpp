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
Node *insertion(Node*root,int value)
{
    if(root == 0)
    {
        Node *n = new Node(value);
        return n;
    }
    if(value<root->data)
    {
        root->left = insertion(root->left,value);
    }
    else if(value>root->data)
    {
        root->right = insertion(root->right,value);
    }
    return root;
}
int main()
{
    return 0;
}