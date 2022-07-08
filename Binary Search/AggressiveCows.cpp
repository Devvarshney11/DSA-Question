#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isPossible(vector<int> arr, int n, int k, int mid)
{
    int cows = 1;
    int lastpos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastpos >= mid)
        {
            cows++;
            if (cows == k)
                return true;
            lastpos = arr[i];
        }
    }
    return false;
}
int findMinimumDistance(vector<int> arr, int n, int k)
{
    sort(arr.begin(),arr.end());
    int low = 0;
    int high = arr[n-1];
    int ans = 0;
    while(low<=high)
    {
        int mid = low + (high - low)/2;

        if(isPossible(arr,n,k,mid))
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    int k = 2;
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);
    cout<<findMinimumDistance(arr,n,k);
    return 0;
}