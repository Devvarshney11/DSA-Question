#include<iostream>

using namespace std;
/*
int findDuplicate(int *arr, int n)
{
    int sum = 0;
    int originalsum = 0;
    for(int i = 0;i<n;i++)
    {
        if(i+1 != n)
        {
           sum += i+1;
        }
        originalsum += arr[i];
    }
    return (originalsum-sum);
}*/
int findDuplicate(int *arr, int n)
{
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans = ans^arr[i];
    }
    for(int i = 1;i<=n-1;i++)
    {
        ans = ans^i;
    }
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,3,1,4};
    cout<<findDuplicate(arr,n);
    return 0;
}