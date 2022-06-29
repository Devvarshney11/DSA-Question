#include<iostream>
#include<algorithm>
using namespace std;
void selectionSort(int *arr, int n)
{
    for(int i = 0;i<n-1;i++)
    {
       int min = i;
       for(int j = i+1;j<n;j++)
       {
         if(arr[j]<arr[min])
         {
            min = j;
         }
       }
       if(min != i)
       {
        swap(arr[min],arr[i]);
       }
    }
}
int main()
{
    int n = 5;
    int arr[n] = {2,9,6,4,1};
    selectionSort(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}