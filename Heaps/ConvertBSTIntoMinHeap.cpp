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
void inorder(Node *root, vector<int> &minHeap)
{
    if (root == 0)
        return;
    inorder(root->left, minHeap);
    minHeap.push_back(root->data);
    inorder(root->right, minHeap);
}
void preorder(vector<int> &minHeap, int &i, Node *&root)
{
    if (root == 0)
    {
        return;
    }
    root->data = minHeap[i];
    i++;
    preorder(minHeap, i, root->left);
    preorder(minHeap, i, root->right);
}
Node *convertBSTIntoMinHeap(Node *root)
{
    vector<int> minHeap;
    inorder(root,minHeap);

    int i = 0;
    preorder(minHeap,i,root);
    return root;
}
int main()
{
    return 0;
}