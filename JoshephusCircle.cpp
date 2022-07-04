#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int i)
    {
        data = i;
        next = 0;
    }
};
void insert(node *&head, node *&tail, int i)
{
    node *n = new node(i);
    if (head == 0 && tail == 0)
    {
        head = tail = n;
        n->next = tail;
        return;
    }
    n->next = head;
    tail->next = n;
    tail = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
node *getPosition(node *head,int m,int n)
{
    for(int i = n ;i>1;--i)
    {
        for(int j = 0;j<m-1;j++)
        {
            head = head->next;
        }
        cout<<head->data<<" has killed"<<endl;
        head->next = head->next->next;
    }
    return head;
}
int main()
{
    node *head = 0;
    node *tail = 0;
    insert(head, tail, 1);
    insert(head, tail, 2);
    insert(head, tail, 3);
    insert(head, tail, 4);
    insert(head, tail, 5);
    display(head);
    cout<<getPosition(head,2,5)->data<<endl;
    return 0;
}