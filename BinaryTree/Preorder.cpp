#include<iostream>
#include<stack>

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
void preorder(node *root)
{
    if(root == 0)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


//By Iterative mean by stack
void preorder(node *root)
{
    if(root == 0)
        return;
    stack<node*> st;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            st.push(root);
            root = root->left;
        }
        if(st.empty())
        {
            break;
        }
        root = st.top()->right;
        st.pop();
    }
}
int main()
{
return 0;
}