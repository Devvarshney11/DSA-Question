#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = 0;
        right = 0;
    }
};

void print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printPath(node *root, int *arr, int len)
{
    if (root == 0)
        return;
    arr[len] = root->data;
    len++;
    if(!root->left && !root->right)
    {
        print(arr,len);
    }
    else
    {
        printPath(root->left,arr,len);
        printPath(root->right,arr,len);
    }
}
int main()
{
    return 0;
}