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

void postorder(node *root)
{
    if(root == 0)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//By iteration
void postorder(node *root)
{
    if(root == 0)
        return;
    node *prev = nullptr;
    stack<node*> st;
    do
    {
       while(root)
       {
            st.push(root);
            root = root->left;
       }
       while(root == nullptr && !st.empty())
       {
            root = st.top();
            if(root->right == 0 || root->right == prev)
            {
                cout<<root->data<<" ";
                prev = root;
                root = nullptr;
                st.pop();
            }
            else
            {
                root = root->right;
            }
       }
    } while (!st.empty());
    
}
int main()
{
    return 0;
}