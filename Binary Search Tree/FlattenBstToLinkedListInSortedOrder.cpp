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
Node *flatten(Node *root)
{
    if (root == 0)
        return nullptr;
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *n = new Node(arr[i]);
        temp->left = 0;
        temp->right = n;
        temp = n;
    }
    temp->left = 0;
    temp->right = 0;
    return head;
}
int main()
{
    return 0;
}