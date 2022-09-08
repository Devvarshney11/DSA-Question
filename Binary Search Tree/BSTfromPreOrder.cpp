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

void inorder(Node *root, vector<int> &arr)
{
    if (root == 0)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
Node *create(vector<int> &in, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (low + high) >> 1;
    Node *root = new Node(in[mid]);
    root->left = create(in, low, mid - 1);
    root->right = create(in, mid + 1, high);
    return root;
}
Node *balancedBst(Node *root)
{
    if (root == 0)
        return nullptr;
    vector<int> arr;
    inorder(root, arr);
    Node *ans = create(arr, 0, arr.size() - 1);
    return ans;
}

int main()
{
    return 0;
}