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

pair<bool, int> Sum(Node *root)
{
    if (root == 0)
    {
        return {true, 0};
    }
    if (!root->left && !root->right)
    {
        return {true, root->data};
    }
    pair<bool, int> left = Sum(root->left);
    pair<bool, int> right = Sum(root->right);

    bool check = (root->data == left.second + right.second);

    pair<bool, int> p;
    p.second = root->data + left.second + right.second;
    if (left.first && right.first && check)
    {
        p.first = true;
    }
    else
    {
        p.first = false;
    }
    return p;
}
bool isSumTree(Node *root)
{
    if (root == 0)
        return true;
    pair<bool, int> p = Sum(root);
    return p.first;
}
int main()
{
    return 0;
}