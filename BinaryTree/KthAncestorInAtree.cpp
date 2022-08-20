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

Node *solve(Node *root, int &k , int node)
{
    if(root == 0)
        return 0;
    if(root->data == node)
    {
        return root;
    }
    Node *left = solve(root->left,k,node);
    Node *right = solve(root->right,k,node);
    
    if(left  && !right)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if(!left && right)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    if(root == 0)
        return 0;
    Node *ans = solve(root,k,node);
    if(ans == 0 || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}

int main()
{
    return 0;
}