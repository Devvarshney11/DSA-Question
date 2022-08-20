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
int sum(node *root)
{
    if (root == 0)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

// By iteration
int sum(node *root)
{
    if(root == 0)
    {
        return 0;
    }
    int s = 0;
    queue<node *> q;
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        s += temp->data;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return s;
}

int main()
{
    return 0;
}