// You are given a linked list containing N nodes,
// where every node in the linked list contains two pointers,
// first one is ‘NEXT’ which points to the next node in the list and
// the second one is ‘CHILD’ pointer to a linked list where the head is this node.
// And each of these child linked lists is in sorted order.
// Your task is to flatten this linked such that all nodes appear in a single layer or level
// while the nodes should maintain the sorted order.
// #include <bits/stdc++.h>
// i/p:-
// 3 4 6  -1
// 5 11 14 -1
// 22 25 -1
// 26 28 -1
// 39  -1
// o/p:-
// 3 4 5 6 11 14 22 25 26 28 39
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *result;
    if (a->data < b->data)
    {
        result = a;
        result->child = merge(a->child, b);
    }
    else
    {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    return merge(head, flattenLinkedList(head->next));
}
int main()
{
    return 0;
}