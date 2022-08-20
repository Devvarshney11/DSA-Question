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

void deleteDeepest(node *root, node *del)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp->left)
        {
            if(temp->left == del)
            {
                delete temp->left;
                temp->left = 0;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
        if(temp->right)
        {
            if(temp->right == del)
            {
                delete temp->right;
                temp->right = 0;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
} 
node *deleteNode(node *root,int val)
{
    if(root == 0)
        return 0;
    if(!root->left && !root->right)
    {
        if(root->data == val)
            return 0;
        return root;
    }
    queue<node *> q;
    q.push(root);
    node *temp;
    node *flag = nullptr;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == val)
        {
            flag = temp;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(flag) 
    {
        flag->data = temp->data;
        deleteDeepest(root,temp);
    }
    return root;
}
int main()
{
    return 0;
}