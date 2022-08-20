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

node *deepestNode(node *root)
{
    if (root == 0)
        return 0;

    queue<node *> q;
    q.push(root);
    node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return temp;
}

int main()
{
    return 0;
}