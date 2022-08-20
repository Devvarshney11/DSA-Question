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

int countLeafs(node *root)
{
    if(root == 0)
    {
        return 0;
    }
    node *temp;
    queue<node *> q;
    q.push(root);
    int count = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(!temp->left && !temp->right)
        {
            count++;
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return count;
}
int main()
{
    return 0;
}