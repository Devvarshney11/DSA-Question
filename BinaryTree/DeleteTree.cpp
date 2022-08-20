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

void deleteBT(node *root)
{
    if(root == 0)
        return;
    deleteBT(root->left);
    deleteBT(root->right);
    delete root;
}
int main()
{
    return 0;
}