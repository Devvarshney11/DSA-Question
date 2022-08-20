#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = 0;
        right = 0;
    }
};

// By recursion
bool search(node *root, int val)
{
    if (root == 0)
        return false;
    if (val == root->data)
        return true;
    if (!search(root->left, val))
    {
        return search(root->right, val);
    }
    return true;
}

//By iteration

bool search(node *root , int val)
{
    if(root == 0)
        return false;
    if(root->data == val)
        return true;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp->data == val)
            return true;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return false;
}
int main()
{
    return 0;
}