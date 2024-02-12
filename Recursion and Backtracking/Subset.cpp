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

Node *insert(Node *root, int key)
{
    if (root == 0)
    {
        Node *n = new Node(key);
        root = n;
        return root;
    }
    if (root->data > key)
        root->left = insert(root->left, key);
    else if (root->data < key)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate not allowed" << endl;
    return root;
}
Node *maxEle(Node *root)
{
    if (root == 0)
        return NULL;
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}
Node *minEle(Node *root)
{
    if (root == 0)
        return NULL;
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deleteion(Node *root, int val)
{
    if (root == 0)
    {
        cout << "Node not found" << endl;
        return;
    }
    if (root->data > val)
    {
        root->left = deleteion(root->left, val)
    }
    else if(root->data < val)
    {
        root->right = deleteion(root->right,val);
    }
    else 
    {
        if(!root->left)
        {
            Node*temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else 
        {
            Node *max = maxEle(root);

        }
    }
}
//flatten BST into linked list
void flattenBST(Node *root,Node *&head)
{
    if(root == 0)
        return;
    flattenBST(root->right,head);
    root->right = head;
    if(head == 0)
        head->left = 0;
    head = root;
    flattenBST(root->left,head);
}
int main()
{
    return 0;
}