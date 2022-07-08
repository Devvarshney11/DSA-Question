// We have to paint n boards of length {A1, A2…An}.
// There are k painters available and each takes 1 unit time to paint 1 unit of board.
// The problem is to find the minimum time to get
// this job done under the constraints that any painter will
// only paint continuous sections of boards,
// say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
#include <iostream>
using namespace std;
bool isPossible(int *arr, int n, int k, int mid)
{
    int time = 0;
    int painter = 1;
    for (int i = 0; i < n; i++)
    {
        time += arr[i];
        if (time > mid)
        {
            time = arr[i];
            painter++;
        }
    }
    return (painter <= k);
}
int findMinimumTime(int *arr, int n, int k)
{
    int low = 0;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += arr[i];
        if (low < arr[i])
        {
            low = arr[i];
        }
    }
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid))
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
    int k = 2;
    int arr[n] = {20,10,30,40};
    cout<<findMinimumTime(arr,n,k);
    return 0;
}