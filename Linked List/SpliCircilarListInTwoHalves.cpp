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
void insert(node *&head ,node *&tail , int i)
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
void splitList(node *head,node *&a, node *&b)
{
     if(head == 0 || head->next == 0)
     {
        a = head;
        b = 0;
        return;
     }
     node *fast = head->next;
     node *slow = head;
     while(fast != head)
     {
        fast = fast->next;
        if(fast != head)
        {
            fast = fast->next;
            slow = slow->next;
        }
     }
     a = head;
     b = slow->next;
     node *temp = b;
     slow->next = head;
     while(temp->next != head)
     {
        temp = temp->next;
     }
     temp->next = b;
}
int main()
{
    node *head = 0;
    node *tail = 0;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,3);
    insert(head,tail,4);
    insert(head,tail,5);
    display(head);
    node *a;
    node *b;
    splitList(head,a,b);
    display(a);
    display(b);
    return 0;
}