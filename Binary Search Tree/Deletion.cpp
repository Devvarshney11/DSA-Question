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

Node *deletion(Node *root,int key)
{
    if(root == 0)
        return 0;
    if(root->data>key)
        root->left = deletion(root->left,key);
    else if(root->data<key)
        root->right = deletion(root->right,key);
    else
    {
        if(!root->left)
        {
            Node *temp = root->right;
            delete root; 
            return temp;
        }
        else if(!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = min(root->right);
            root->data = temp->data;
            root->right = deletion(root->right,temp->data);
        }
        return root;
    }
}
int main()
{
    return 0;
}