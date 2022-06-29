#include<bits/stdc++.h>
using namespace std;

int firstPositon(int *arr, int n , int key)
{
    int low = 0;
    int high = n-1;

    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == key)
        {
           ans = mid;
           high = mid-1;
        }
        else if(arr[mid]<key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}
int lastPositon(int *arr, int n , int key)
{
    int low = 0;
    int high = n-1;

    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == key)
        {
           ans = mid;
           low = mid+1;
        }
        else if(arr[mid]<key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    int arr[5] = {1,2,3,3,5};
    cout<<"The first position is : "<<firstPositon(arr,n,3)<<endl;
    cout<<"The last position is : "<<lastPositon(arr,n,3);
    return 0;
}