#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &heap,int i,int n)
{
    int l = 2*i+1;
    int r = 2*i+2;

    int s = i;
    if(l<n && heap[l]>heap[s])
    {
        s = l;
    }
    if(r<n && heap[r]>heap[s])
    {
        s = r;
    }
    if(s != i)
    {
        swap(heap[s],heap[i]);
        heapify(heap,s,n);
    }
}
vector<int> mergeHeaps(vector<int> heap1,vector<int> heap2)
{
    int n = heap1.size();
    int m = heap2.size();
    vector<int> heap;
    for(int i = 0;i<n;i++)
    {
        heap.push_back(heap1[i]);
    }
    for(int i = 0;i<m;i++)
    {
        heap.push_back(heap2[i]);
    }
    int k = n+m;
    for(int i = k/2-1;i>=0;i--)
    {
        heapify(heap,i,k);
    }
    return heap;
}

int main()
{
    return 0;
}