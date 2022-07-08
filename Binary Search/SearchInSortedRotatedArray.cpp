#include <iostream>

using namespace std;

// int search(int *arr, int n, int key)
// {
//     int low = 0;
//     int high = n-1;
//     while(low<=high)
//     {
//         int mid = low + (high - low)/2;
//         if(arr[mid] == key)
//         return mid;
//         else if(arr[mid]>arr[low])
//         {
//             if(key>=arr[low] && key<arr[mid])
//             {
//                 high = mid-1;
//             }
//             else
//             {
//                 low = mid+1;
//             }
//         }
//         else
//         {
//             if(key>arr[mid] && key<= arr[high])
//             {
//                 low = mid+1;
//             }
//             else
//             {
//                 high = mid-1;
//             }
//         }
//     }
//     return -1;
// }
int pivotElement(int *arr, int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}
int search(int *arr, int n, int key)
{
    if (n == 1)
    {
        return (arr[0] == key) ? 0 : -1;
    }
    int p = pivotElement(arr, n);
    int low = 0;
    int high = n - 1;
    if (key >= arr[0] && key <= arr[p - 1])
    {
        low = 0;
        high = p - 1;
    }
    else
    {
        low = p;
        high = n - 1;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[n] = {7, 9, 1, 2, 3};
    cout << "The index is : " << search(arr, n, 1);
    return 0;
}