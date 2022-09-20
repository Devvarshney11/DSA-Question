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
        left = 0;
        right = 0;
    }
    Node()
    {
        data = 0;
        left = 0;
        right = 0;
    }
};
Node *create(Node *root, int value)
{
    if (root == 0)
    {
        Node *n = new Node(value);
        return n;
    }
    else if (root->data > value)
    {
        root->left = create(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = create(root->right, value);
    }
    else
    {
        cout << "Duplicates Not Allowed" << endl;
    }
    return root;
}
// Max Element in BST
Node *maxEle(Node *root)
{
    while (root->right != 0)
    {
        root = root->right;
    }
    return root;
}
// Min Element in BST
Node *minEle(Node *root)
{
    while (root->left != 0)
    {
        root = root->left;
    }
    return root;
}
// Deletion of Node
Node *Deletion(Node *root, int value)
{
    if (root == 0)
    {
        cout << "Target Not Found" << endl;
        return root;
    }
    else if (root->data > value)
    {
        root->left = Deletion(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = Deletion(root->right, value);
    }
    else
    {
        if (!root->left)
        {
            Node *x = root->right;
            delete root;
            return x;
        }
        else if (!root->right)
        {
            Node *x = root->right;
            delete root;
            return x;
        }
        else
        {
            Node *x = minEle(root->right);
            root->data = x->data;
            Deletion(root->right, x->data);
        }
    }
    return root;
}
// MorrisTraversal
void morrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->left == 0)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != 0 && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == 0)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}
// Inorder
void inorder(Node *root)
{
    if (root == 0)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// PostOrder
void postorder(Node *root)
{
    if (root == 0)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// Preorder
void preorder(Node *root)
{
    if (root == 0)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// LevelOrder
void levelOrder(Node *root)
{
    if (root == 0)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
// Validate BST
bool valid(Node *root, int low, int high)
{
    if (root == 0)
        return true;
    if (root->data > low && root->data < high)
    {
        if (valid(root->left, low, root->data))
            return valid(root->right, root->data, high);
    }
    return false;
}
bool validateBST(Node *root)
{
    return valid(root, INT_MIN, INT_MAX);
}
// Kth Smallest
//   By Inorder
int ksmallest(Node *root, int &i, int k)
{
    if (root == 0)
        return -1;
    int left = ksmallest(root->left, i, k);
    if (left != -1)
        return left;
    i++;
    if (i == k)
        return root->data;
    return ksmallest(root->right, i, k);
}
//  By morris traversal
int kthSmallest(Node *root, int k)
{
    if (root == 0)
        return -1;
    Node *curr = root;
    int i = 0;
    while (curr)
    {
        if (curr->left == 0)
        {
            i++;
            if (i == k)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != 0 && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == 0)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                i++;
                if (i == k)
                    return curr->data;
                curr = curr->right;
            }
        }
    }
    return -1;
}
// Kth Largest
int kthLargest(Node *root, int k, int &i)
{
    if (root == 0)
        return -1;
    int right = kthLargest(root->right, k, i);
    if (right != -1)
        return right;
    i++;
    if (i == k)
    {
        return root->data;
    }
    return kthLargest(root->left, k, i);
}
// LCA in BST

Node *LowestCommonAnsecstor(Node *root, int a, int b)
{
    if (root == 0)
        return 0;
    if (root->data > a && root->data > b)
    {
        return LowestCommonAnsecstor(root->left, a, b);
    }
    if (root->data < a && root->data < b)
    {
        return LowestCommonAnsecstor(root->right, a, b);
    }
    return root;
}
// Two Sum In BST
void morrisTraversal(Node *root, vector<int> &tree)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->left == 0)
        {
            tree.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != 0 && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == 0)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                tree.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}
bool twoSum(Node *root, int target)
{
    if (root == 0)
        return false;
    vector<int> tree;
    morrisTraversal(root, tree);
    int i = 0;
    int j = tree.size() - 1;
    while (i < j)
    {
        int sum = tree[i] + tree[j];
        if (sum == target)
            return true;
        else if (sum > target)
            j--;
        else
            i++;
    }
    return true;
}
// Normal BST to Balanced BST
Node *createBSTFromInorder(vector<int> in, int low, int high)
{
    if (low > high)
        return 0;
    int mid = (low + high) >> 1;
    Node *n = new Node(in[mid]);
    n->left = createBSTFromInorder(in, low, mid - 1);
    n->right = createBSTFromInorder(in, mid + 1, high);
    return n;
}
Node *balancedBST(Node *root)
{
    vector<int> in;
    morrisTraversal(root, in);
    Node *newRoot = createBSTFromInorder(in, 0, in.size() - 1);
    return newRoot;
}
// Flatten BST to Sorted List : Inorder of BST is Sorted so we use morris Traversal

Node *flattenBST(Node *root)
{
    vector<int> tree;
    morrisTraversal(root, tree);
    Node *head = new Node(tree[0]);
    head->left = 0;
    Node *temp = head;
    for (int i = 1; i < tree.size(); i++)
    {
        temp->right = new Node(tree[i]);
        temp = temp->right;
        temp->left = 0;
    }
    return head;
}
// BST from Preorder
Node *solve(vector<int> &pre, int &i, int mini, int maxi)
{
    if (i >= pre.size())
        return 0;
    if (pre[i] < mini || pre[i] > maxi)
        return NULL;
    Node *n = new Node(pre[i++]);
    n->left = solve(pre, i, mini, n->data);
    n->right = solve(pre, i, n->data, maxi);
    return n;
}

Node *BSTfromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
        return 0;
    int i = 0;
    return solve(preorder, i, INT_MIN, INT_MAX);
}
// Merge 2 BST
// Apparoach 1
void inorder(Node *root, vector<int> &arr)
{
    if (root == 0)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr3.push_back(arr1[i++]);
        else
            arr3.push_back(arr2[j++]);
    }
    while (i < n)
    {
        arr3.push_back(arr1[i++]);
    }
    while (j < m)
    {
        arr3.push_back(arr2[j++]);
    }
}
Node *create(vector<int> in, int low, int high)
{
    if (low > high)
        return 0;
    int mid = low + ((high - low) >> 1);
    Node *n = new Node(in[mid]);
    n->left = create(in, low, mid - 1);
    n->right = create(in, mid + 1, high);
    return n;
}
Node *mergeBST(Node *root1, Node *root2)
{
    if (root1 == 0)
        return root2;
    if (root2 == 0)
        return root1;
    // Step1 : Create sorted array from both Bst
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    // Step2 : Merge both array in thrd array
    vector<int> arr3;
    merge(arr1, arr2, arr3);

    // Step3 : Create BSt from inorder
    int n = arr3.size() - 1;
    return create(arr3, 0, n);
}
// Apparoach 2
//  Convert BST to DLL
void convertBSTToDLL(Node *root, Node *&head)
{
    if (root == 0)
    {
        return;
    }
    convertBSTToDLL(root->right, head);

    root->right = head;
    if (head != 0)
        head->left = root;
    head = root;

    convertBSTToDLL(root->left, head);
}
// Merge two sorted linked list
void mergeTwoSortedLinkedList(Node *head1, Node *head2, Node *&head3)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    head3 = new Node(-1);
    Node *temp3 = head3;
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            temp3->right = temp1;
            temp1->left = temp3;
            temp3 = temp1;
            temp1 = temp1->right;
        }
        else
        {
            temp3->right = temp2;
            temp2->left = temp3;
            temp3 = temp2;
            temp2 = temp2->right;
        }
    }
    while (temp1)
    {
        temp3->right = temp1;
        temp1->left = temp3;
        temp3 = temp1;
        temp1 = temp1->right;
    }
    while (temp2)
    {
        temp3->right = temp2;
        temp2->left = temp3;
        temp3 = temp2;
        temp2 = temp2->right;
    }
    temp3->right = 0;
    head3 = head3->right;
    head3->left = 0;
}
int countNodes(Node *head)
{
    int n = 0;
    while (head)
    {
        head = head->right;
        n++;
    }
    return n;
}
// Convert Linked List to Dll
Node *convertLLToBST(Node *&head, int n)
{
    if (n <= 0 || head == 0)
        return 0;
    Node *left = convertLLToBST(head, n / 2);

    Node *root = head;
    head = head->right;

    root->left = left;
    root->right = convertLLToBST(head, n - n / 2 - 1);

    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{
    Node *head1 = 0;
    convertBSTToDLL(root1, head1);
    Node *head2 = 0;
    convertBSTToDLL(root2, head2);

    Node *head3 = 0;
    mergeTwoSortedLinkedList(head1, head2, head3);

    int n = countNodes(head3);

    return convertLLToBST(head3, n);
}
// Size of Largest BST in a Binary Tree
class info
{
public:
    int mini;   // The value of smallest node in the tree
    int maxi;   // The value of the largest node in the tree
    bool isBST; // Check statement if the tree is Bst or not
    int size;   // The size of the tree
};
info solve(Node *root, int &maxSize)
{
    if (root == 0)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currBST;

    currBST.mini = min(root->data, left.mini);
    currBST.maxi = max(root->data, right.maxi);

    currBST.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini)
    {
        currBST.isBST = true;
    }
    else
    {
        currBST.isBST = false;
    }
    if (currBST.isBST)
    {
        maxSize = max(maxSize, currBST.size);
    }
}
int largestBST(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
// Algorithm for filling the nextsibling pointer
class node
{
public:
    int data;
    node *nextSibling;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        nextSibling = 0;
        left = 0;
        right = 0;
    }
};
// By iteration
// void fillNextSibling(node *&root)
// {
//     if (root == 0)
//         return;
//     queue<node*> q;
//     q.push(root);
//     q.push(0);
//     while(!q.empty())
//     {
//         node *temp = q.front();
//         q.pop();
//         if(temp == 0)
//         {
//             if(!q.empty())
//             {
//                 q.push(0);
//             }
//         }
//         else
//         {
//             temp->nextSibling = q.front();
//             if(temp->left)
//                 q.push(temp->left);
//             if(temp->right)
//                 q.push(temp->right);
//         }
//     }
// }
// By recursion
void fillNextSibling(node *root)
{
    if (root == 0)
        return;
    root->left->nextSibling = root->right;
    root->right->nextSibling = (root->nextSibling->left) ? root->nextSibling->left : 0;

    fillNextSibling(root->left);
    fillNextSibling(root->right);
}
// Given a BST of size n , in which each node r has an additional field r->size,
// The number of sub tree rooted at r(including the root node r),we have to write algo to find
// the number nodes strictly greater than k;
class tree
{
public:
    int data;
    tree *left;
    tree *right;
    int size;
};
int greaterThanK(tree *root, int k)
{
    if (root == 0)
        return 0;
    int n = 0;
    while (root)
    {
        if (k < root->data)
        {
            n += root->right->size + 1;
            root = root->left;
        }
        else if (k > root->data)
        {
            root = root->right;
        }
        else
        {
            n += root->right->size;
            break;
        }
    }
    return n;
}
int main()
{
    Node *root = 0;
    root = create(root, 5);
    root = create(root, 3);
    root = create(root, 7);
    root = create(root, 2);
    root = create(root, 9);
    root = create(root, 6);
    root = create(root, 8);
    root = create(root, 1);
    morrisTraversal(root);
    root = Deletion(root, 5);
    morrisTraversal(root);
}