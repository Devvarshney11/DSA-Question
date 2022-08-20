#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

int hasPath(node *root, int sum)
{
    if (root == 0)
    {
        return (sum == 0);
    }
    int rem = sum-root->data;
    if((root->left && root->right) || (!root->left && !root->right))
    {
        return(hasPath(root->left,rem) || hasPath(root->right,rem));
    }
    else if(root->right)
    {
        return(hasPath(root->right,rem));
    }
    else
    {
        return(hasPath(root->left,rem));
    }
}
int main()
{
    return 0;
}