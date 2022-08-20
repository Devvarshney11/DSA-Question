#include <iostream>

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

int height(node *root)
{
    if (root == 0)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left > right) ? left + 1 : right + 1;
}
int diameter(node *root)
{
    if (root == 0)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    return max(left + right + 1, max(diameter(root->left), diameter(root->right)));
}
int main()
{
    return 0;
}