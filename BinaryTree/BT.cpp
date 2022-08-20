#include <iostream>
#include <queue>
using namespace std;

class node
{
    public:
        int data;
        node *left;
        node *right;
        
        node(int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};
node *insert()
{
    int i;
    cout<<"Enter the value of node or 0 for exit : ";
    cin>>i;
    if(!i)
        return 0;
    node *n = new node(i);
    cout<<"Creating left node of "<<i<<" node : "<<endl;
    n->left = insert();
    cout<<"Creating right node of "<<i<<" node : "<<endl;
    n->right = insert();
    return n;
}
void inorder(node *root)
{
    if(root == 0)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
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
    node *root = insert();
    levelOrder(root);
    return 0;
}