#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int temp[high - low + 1];
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for(int i = low ;i<=high;i++)
    {
       arr[i] = temp[k++];
    }
}
void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
}
int main()
{
    
    int n = 10;
    int arr[n] = {2,9,6,4,1,10,34,23,12,11};
    mergeSort(arr,0,n-1);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}