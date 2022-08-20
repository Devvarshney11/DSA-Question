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
int size(node *root)
{
    if (root == 0)
        return 0;
    return size(root->left) + 1 + size(root->right);
}

//By iteration

int size(node *root)
{
    int count = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        count++;
        if(temp->left) 
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return count;
}

int main()
{
    return 0;
}