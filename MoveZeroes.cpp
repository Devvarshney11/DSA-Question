#include<iostream>
#include<algorithm>
using namespace std;

void moveZero(int *arr, int n)
{
    int start = 0;
    int end = 0;
    while(end<n)
    {
        if(arr[end] != 0)
        {
            swap(arr[start],arr[end]);
            start++;
        }
        end++;
    }
}
int main()
{
    int n = 6;
    int arr[n] = {0,0,0,0,1,2};
    moveZero(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}