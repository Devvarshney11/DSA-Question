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
int kthSmallest(Node *root, int k)
{
    if (root == 0)
        return -1;
    int i = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->right == 0)
        {
            i++;
            if (i == k)
                return curr->data;
            curr = curr->left;
        }
        else
        {
            Node *pred = curr->right;
            while (pred->left != 0 && pred->left != curr)
            {
                pred = pred->left;
            }
            if (pred->left == 0)
            {
                pred->left = curr;
                curr = curr->right;
            }
            else
            {
                pred->left = 0;
                i++;
                if (i == k)
                    return curr->data;
                curr = curr->left;
            }
        }
    }
    return -1;
}
int main()
{
    return 0;
}