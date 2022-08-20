#include <iostream>
#include <stack>

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

void inorder(node *root)
{
    if(root == 0)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//By iteration

void inorder(node *root)
{
    if(root == 0)
        return;
    stack<node*> st;
    while(1)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        if(st.empty())
            break;
        root = st.top();
        st.pop();
        cout<<root->data;
        root = root->right;
    }
}
int main()
{
    return 0;
}