//The smallest element in rotated sorted array is called pivot element

#include<iostream>

using namespace std;
int pivotElement(int *arr, int n)
{
    int low = 0;
    int high = n-1;
    while(low<high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid]>arr[0])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return arr[low];
}
int main()
{
    int n = 5;
    int arr[n] = {7,9,10,2,3};
    cout<<pivotElement(arr,n);
    return 0;
}