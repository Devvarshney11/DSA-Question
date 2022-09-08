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
void inorder(Node* root,vector<int> &arr)
{
    if(root == 0)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
bool twoSumInBST(Node* root, int target) {
    vector<int> arr;
    inorder(root,arr);
    int left = 0;
    int right = arr.size()-1;
    while(left<right)
    {
        int sum = arr[left] + arr[right];
        if(sum == target)
            return true;
        else if(sum<target)
            left++;
        else 
            right--;
    }
    return false; 
}
int main()
{
    return 0;
}