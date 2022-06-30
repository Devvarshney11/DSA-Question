#include<iostream>

using namespace std;

bool check(int *arr,int n)
{
    if(n == 0 || n == 1)
    return true;
    if(arr[0]<arr[1])
    {
        return check(arr+1,n-1);
    }
    else
    return false;
}
int main()
{
    int arr[5] = {1,2,3,4,2};
    cout<<check(arr,5);
    return 0;
}