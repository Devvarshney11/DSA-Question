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
//By inorder Traversal
int smallest(Node *root, int k, int &i)
{
    if (root == 0)
        return -1;
    int left = smallest(root->left, k, i);
    if (left != -1)
        return left;
    i++;
    if (i == k)
        return root->data;
    return smallest(root->right, k, i);
}
int kthSmallest(Node *root, int k)
{
    if(root == 0)
        return -1;
    int i = 0;
    return smallest(root,k,i);
}
//By morris Traversal
int kthSmallest(Node *root, int k)
{
    if (root == 0)
        return -1;
    int i = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->left == 0)
        {
            i++;
            if (i == k)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != 0 && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == 0)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = 0;
                i++;
                if (i == k)
                    return curr->data;
                curr = curr->right;
            }
        }
    }
    return -1;
}
int main()
{
    return 0;
}