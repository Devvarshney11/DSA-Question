#include<iostream>
#include<algorithm>
using namespace std;
// void selectionSort(int *arr, int n)
// {
//     for(int i = 0;i<n-1;i++)
//     {
//        int min = i;
//        for(int j = i+1;j<n;j++)
//        {
//          if(arr[j]<arr[min])
//          {
//             min = j;
//          }
//        }
//        if(min != i)
//        {
//         swap(arr[min],arr[i]);
//        }
//     }
// }
void selectionSort(int *arr,int n,int i)
{
    if(i == n-1)
    return;
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
    selectionSort(arr,n,i+1);
}
int main()
{
    int n = 5;
    int arr[n] = {2,9,6,4,1};
    selectionSort(arr,n,0);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}