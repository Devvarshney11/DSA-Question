#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
};

vector<int> diagonalView(Node *root)
{
    vector<int> ans;
    if(root == 0)
        return ans;
    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while(temp)
        {
            if(temp->left)
                q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}
int main()
{
return 0;
}