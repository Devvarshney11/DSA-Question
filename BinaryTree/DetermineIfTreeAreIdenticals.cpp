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

bool isIdentical(Node *r1, Node *r2)
{
    if (!r1 && !r2)
        return true;
    if (r1 && !r2 || !r1 && r2)
        return false;
    if (r1->data == r2->data)
    {
        if (isIdentical(r1->left, r2->left))
        {
            return isIdentical(r1->right, r2->right);
        }
        else
        {
            return false;
        }
    }
    else
        return false;
}
int main()
{
    return 0;
}