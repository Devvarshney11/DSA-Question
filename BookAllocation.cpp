#include<iostream>

using namespace std;

bool isPossible(int *arr, int n, int m, int mid)
{
    int sum = 0;
    int count = 1;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
        if(sum>mid)
        {
            count++;
            sum = arr[i];
        }
    }
    return (count<=m);
}
int findMinimumPages(int *arr, int n, int m)
{   
    int low = 0;
    int high = 0;
    for(int i = 0;i<n;i++)
    {
        high += arr[i];
        if(arr[i]>low)
        {
            low = arr[i];
        }
    }
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n = 4;
    int m = 2;
    int arr[n] = {20,10,30,40};
    cout<<findMinimumPages(arr,n,m);
    return 0;
}