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

int Level(node *root)
{
    int sum = 0, level = 0, maxlevel = 0, maxsum = 0;
    queue<node *> q;
    q.push(root);
    q.push(0);
    node *temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp == 0)
        {
            if(sum>maxsum)
            {
                maxsum = sum;
                maxlevel = level;
            }
            level++;
            sum = 0;
            if(!q.empty())
            {
                q.push(0);
            }
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return maxlevel;
}
int main()
{
    return 0;
}