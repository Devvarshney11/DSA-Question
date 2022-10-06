#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
node *mergeKSortedList(vector<node *> kList)
{
    int k = kList.size();
    if (k == 0)
        return nullptr;
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        if (kList[i] != nullptr)
            pq.push(kList[i]);
    }
    node *head = 0;
    node *tail = 0;
    while(pq.size()>0)
    {
        node *temp = pq.top();
        pq.pop();
        if(temp->next != 0)
        {
            pq.push(temp->next);
        }
        if(head == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}
int main()
{
    return 0;
}