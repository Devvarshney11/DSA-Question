#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
// By queue
vector<int> zigzag(node *root)
{
    vector<int> result;
    if (root == 0)
        return result;
    queue<node *> q;
    q.push(root);
    bool LefttoRight = true;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();
            int index = LefttoRight ? i : n - i - 1;
            arr[index] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        LefttoRight = !LefttoRight;

        for (int i : arr)
        {
            result.push_back(i);
        }
    }
    return result;
}

// By stack

vector<int> zigzag(node *root)
{
    vector<int> result;
    if (root == 0)
        return result;
    stack<node *> q;
    stack<node *> next;
    q.push(root);
    bool LefttoRight = true;
    while (!q.empty())
    {
        node *temp = q.top();
        q.pop();
        result.push_back(temp->data);
        if(LefttoRight) 
        {
            if(temp->left)
                next.push(temp->left);
            if(temp->right)
                next.push(temp->right);
        }
        else
        {
             if(temp->right)
                next.push(temp->right);
             if(temp->left)
                next.push(temp->left);
        }
        if(q.empty())
        {
            LefttoRight = !LefttoRight;
            swap(q,next);
        }
    }
    return result;
}

int main()
{
    return 0;
}