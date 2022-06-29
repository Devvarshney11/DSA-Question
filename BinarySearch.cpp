#include<iostream>

using namespace std;

int binarySearch(int *arr, int n,int key)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
       int mid = low + (high-low)/2;
       if(arr[mid] == key)
       return mid;
       else if(arr[mid]<key)
       low = mid+1;
       else
       high = mid-1;
    }
    return -1;
}
int main()
{
    int n = 6;
    int arr[n] = {2,5,7,9,10,15};
    int key = 10;
    cout<<"index is : "<<binarySearch(arr,n,key)<<endl;    
    return 0;
}