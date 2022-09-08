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
//By Ranges
bool isvalid(Node *root, int low,int high)
{
    if(root == 0)
        return true;
    if(root->data>low && root->data<high)
    {
        if(isvalid(root->left,low,root->data))
        {
            return isvalid(root->right,root->data,high);
        }
        return false;
    }
    return false;
}
bool validateBST(Node *root) {
    if(root == 0)
        return true;
    return isvalid(root,INT_MIN,INT_MAX);
}

//By inorder
void inorder(Node *root, vector<int> &arr)
{
    if(root == 0)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
bool validateBST(Node *root)
{
    if(root == 0)
        return true;
    vector<int> arr;
    for(int i = 1;i<arr.size();i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}
int main()
{
    return 0;
}