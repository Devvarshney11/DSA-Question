#include <iostream>
#include <stack>
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

void reverseLevelOrder(node *root)
{
    if (root == 0)
        return;

    queue<node *> q;
    stack<int> st;

    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        st.push(temp->data);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    return 0;
}