#include<iostream>

using namespace std;

int findUniqueElement(int *arr, int n)
{
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}
int main()
{
    int n = 7;
    int arr[n] = {3,7,2,2,7,3,4};
    cout<<findUniqueElement(arr,n);
    return 0;
}