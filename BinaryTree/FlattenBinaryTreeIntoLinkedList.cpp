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
void flatten(Node *root)
{
    if(root == 0)
        return;
    Node *curr = root;
    while(curr)
    {
        if(curr->left)
        {
            Node *pred = curr->left;
            while(pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main()
{
    return 0;
}