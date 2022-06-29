#include <iostream>

using namespace std;

int peakIndex(int *arr, int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main()
{
    int n = 6;
    int arr[n] = {1,2,3,4,5,1};
    cout<<peakIndex(arr,n)<<endl;
    return 0;
}