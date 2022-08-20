#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

pair<bool, int> balance(Node *root)
{
    pair<bool, int> p;
    if (root == 0)
    {
        p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = balance(root->left);
    pair<bool, int> right = balance(root->right);

    bool diff = (abs(left.second - right.second) <= 1);

    p.second = max(left.second, right.second) + 1;
    if (left.first && right.first && diff)
    {
        p.first = true;
    }
    else
    {
        p.first = false;
    }
    return p;
}
bool isBalanced(Node *root)
{
    if (root == 0)
        return true;
    pair<bool, int> p = balance(root);
    return p.first;
}
int main()
{
    return 0;
}