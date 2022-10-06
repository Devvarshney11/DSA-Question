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
int countNodes(Node *root)
{
    if (root == 0)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCBT(Node *root,int i,int n)
{
    if(root == 0)
        return true;
    if(i>=n)
        return false;
    bool left = isCBT(root->left,2*i+1,n);
    bool right = isCBT(root->right,2*i+2,n);
    
    return (left && right);
}
bool isMaxOrder(Node *root)
{
    if(root->left == 0 && root->right == 0)
        return true;
    if(root->right == 0)
    {
        return root->data>root->left->data;
    }
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);

    return (root->data>root->left->data && root->data>root->right->data)&&left&&right;
}
bool isHeap(Node *root)
{
    int n = countNodes(root);
    int i = 0;
    if(isCBT(root,i,n) && isMaxOrder(root))
    {
        return true;
    }
    return false;
}
int main()
{
    return 0;
}