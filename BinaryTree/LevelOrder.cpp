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

void levelOrder(node *root)
{
    if(root == nullptr)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(0);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp != 0)
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else 
        {
            if(!q.empty())
                q.push(0);
            cout<<endl;
        }
    }
}
int main()
{
    return 0;
}