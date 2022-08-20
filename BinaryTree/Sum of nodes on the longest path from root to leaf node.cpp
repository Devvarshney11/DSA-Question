#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
void solve(Node *root, int n, int &sum, int temp, int &prev)
{
    if (root == 0)
    {
        if (n >= prev)
        {
            if (n == prev)
            {
                sum = max(sum, temp);
            }
            else
            {
                sum = temp;
            }
            prev = n;
        }
        return;
    }
    solve(root->left, n + 1, sum, temp + root->data, prev);
    solve(root->right, n + 1, sum, temp + root->data, prev);
}
int sumOfLongRootToLeafPath(Node *root)
{
    if (root == 0)
        return 0;
    int sum = 0;
    int prev = 0;
    solve(root, 0, sum, 0, prev);
    return sum;
}
int main()
{
    return 0;
}