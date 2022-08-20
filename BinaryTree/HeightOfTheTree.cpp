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

//By recursion

int height(node *root)
{
    if(root == 0)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    return (left>right)?left+1:right+1;
}

// By Iteration

int height(node *root)
{
    if(root == 0)
        return 0;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    int h = 0;
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp == nullptr)
        {
             if(!q.empty())
             {
                q.push(nullptr);
             }
             h++;
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return h;
}
int main()
{
    return 0;
}