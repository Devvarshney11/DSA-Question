#include<iostream>

using namespace std;
bool check(int *arr,int n)
{
    int count = 0;
    for(int i = 1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        count++;
    }
    if(arr[n-1]>arr[0])
    {
        count++;
    }
    return count<=1;
}
int main()
{
    int n = 5;
    int arr[n] = {4,5,1,2,3};
    cout<<check(arr,n);
    return 0;
}