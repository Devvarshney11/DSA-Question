#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(int *arr, int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int temp = 0;
        for(int j = 0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                temp = 1;
            }
        }
        if(temp == 0)
        break;
    }
}
int main()
{
    int n = 5;
    int arr[n] = {2,9,6,4,1};
    bubbleSort(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}