#include <iostream>
#include <queue>
#include <climits>

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

//By iteration(By queue)
int maxElement(node *root)
{
    if(root == 0)
    {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int max = INT_MIN;
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp->data>max)
            max = temp->data;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return max;
}

//By recursion

int maxElement(node *root)
{
    int max = INT_MIN;
    int left,right;
    if(root != 0)
    {
        left = maxElement(root->left);
        right = maxElement(root->right);
        
        max = (left>right)?left:right;

        max = (max>root->data)?max:root->data;
    }
    return max;
}
int main()
{
    return 0;
}