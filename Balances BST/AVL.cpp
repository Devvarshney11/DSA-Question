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
// Height of tree
int height(Node *root)
{
    if (root == 0)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}
// Balance factor
int balancedFactor(Node *root)
{
    return (height(root->left) - height(root->right));
}
// Left Rotation
Node *leftRotation(Node *root)
{
    Node *x = root->right;
    Node *y = x->left;

    x->left = root;
    root->right = y;
    return x;
}
// Right Rotation
Node *rightRotation(Node *root)
{
    Node *x = root->left;
    Node *y = x->right;

    x->left = root;
    root->left = y;

    return x;
}

// Insertion in AVL
Node *insert(Node *root, Node *n)
{
    if (root == 0)
    {
        root = n;
        return;
    }
    else if (root->data > n->data)
    {
        root->left = insert(root->left, n);
    }
    else if (root->data < n->data)
    {
        root->right = insert(root->right, n);
    }
    else
    {
        cout << "Duplicates Not Allowed" << endl;
        return root;
    }
    int bf = balancedFactor(root);
    if (bf == -2 && root->right->data < n->data)
    {
        return leftRotation(root);
    }
    if (bf == 2 && root->left->data > n->data)
    {
        return rightRotation(root);
    }
    if (bf == -2 && root->right->data > n->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    if (bf == 2 && root->left->data < n->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    return root;
}
// Maximum Node in AVL
Node *maxNode(Node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}
// Minimum Node in AVL
Node *minNode(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
// Deletion in AVL
Node *deleteNode(Node *root, int key)
{
    if (root == 0)
    {
        return root;
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == 0)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == 0)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left && root->right)
        {
            Node *temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    int bf = balancedFactor(root);
    if (bf == 2 && balancedFactor(root->left) >= 0)
        return rightRotation(root);
    if (bf == 2 && balancedFactor(root->left) == -1)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if (bf == -2 && balancedFactor(root->right) <= 0)
        return leftRotation(root);
    if (bf == -2 && balancedFactor(root->right) == 1)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

// Check Whether the tree is height balance or not
pair<bool, int> checkBalance(Node *root)
{
    if (root == 0)
    {
        return {true, 0};
    }
    pair<bool, int> left = checkBalance(root->left);
    pair<bool, int> right = checkBalance(root->right);

    bool check = (abs(left.second - right.second) >= 0);

    pair<bool, int> isTrue;
    isTrue.second = (left.second > right.second) ? left.second + 1 : right.second + 1;
    if(check && left.first && right.first)
        isTrue.first = true;
    else 
        isTrue.first = false;
    return isTrue;
}
bool isBalance(Node *root)
{
    if(root == 0)
        return true;
    pair<bool,int> ans = checkBalance(root);
    return ans.first;
}

int main()
{
    return 0;
}