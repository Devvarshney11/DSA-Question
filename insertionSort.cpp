#include<iostream>
#include<algorithm>

using namespace std;

void insertionSort(int *arr, int n)
{
    for(int i = 1;i<n;i++)
    {
        int j = i-1;
        int temp = arr[i];
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int n = 5;
    int arr[n] = {2,9,6,4,1};
    insertionSort(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}