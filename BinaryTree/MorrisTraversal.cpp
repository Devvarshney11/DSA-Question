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

Node *prdecessor(Node *root,Node *current)
{
    while(root->right != NULL && root->right != current)
    {
        root = root->right;
    }
    return root;
}
void MorrisTraversal(Node *root)
{
    if(root == 0)
        return;
    Node *curr = root;
    while(curr)
    {
        if(curr->left == 0)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            Node *pred = prdecessor(curr->left,curr);
            if(pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {   
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
int main()
{
    return 0;
}