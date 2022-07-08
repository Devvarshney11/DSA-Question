#include <iostream>
#include <algorithm>

using namespace std;
int partition(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int i = lb;

    while (lb < ub)
    {
        while (arr[lb] <= pivot)
        {
            lb++;
        }
        while (arr[ub] > pivot)
        {
            ub--;
        }
        if (lb <= ub)
        {
            swap(arr[lb], arr[ub]);
        }
    }
    swap(arr[ub],arr[i]);
    return ub;
}
void quickSort(int *arr, int lb, int ub)
{
    if(lb>=ub)
    {
        return;
    }
    int p = partition(arr,lb,ub);
    quickSort(arr,lb,p-1);
    quickSort(arr,p+1,ub);
}
int main()
{
    int n = 10;
    int arr[n] = {2,9,6,4,1,10,34,23,12,11};
    quickSort(arr,0,n-1);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}