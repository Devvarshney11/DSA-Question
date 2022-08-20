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

Node *createParentMapping(Node *root, int target, map<Node *, Node *> &mp)
{
    Node *t = NULL;

    queue<Node *> q;
    q.push(root);

    mp[root] = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
        {
            t = temp;
        }
        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return t;
}
int burnTree(Node *root, map<Node *, Node *> &mp)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);

    visited[root] = true;
    int time = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = 1;
                flag = 1;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = 1;
                flag = 1;
            }
            if (mp[temp] && !visited[mp[temp]])
            {
                q.push(mp[temp]);
                visited[mp[temp]] = 1;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            time++;
        }
    }
    return time;
}
int minTime(Node *root, int target)
{
    map<Node *, Node *> mp;
    Node *node = createParentMapping(root, target, mp);
    int time = burnTree(node, mp);
    return time;
}
int main()
{
    return 0;
}