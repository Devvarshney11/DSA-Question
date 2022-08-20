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

// By postOrder Traversal
node *mirror(node *root)
{
    if (root == 0)
        return 0;
    mirror(root->left);
    mirror(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}
int main()
{
    return 0;
}