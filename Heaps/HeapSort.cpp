#include <bits/stdc++.h>

using namespace std;

void heapify(int i, int *arr, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(largest,arr,n);
    }
}
void heapSort(int *arr,int n)
{
    if(n == 0)
        return;
    for(int i = n/2-1;i>=0;i--)
    {
        heapify(i,arr,n);
    }
    swap(arr[0],arr[n-1]);
    heapSort(arr,n-1);
}
int main()
{   
    int arr[] = {54,53,55,52,50};
    heapSort(arr,5);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
