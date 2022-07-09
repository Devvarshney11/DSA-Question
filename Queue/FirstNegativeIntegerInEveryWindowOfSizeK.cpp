// Given an array A[] of size N and a positive integer K,
// find the first negative integer for each and every window(contiguous subarray) of size K.

// Example 1:

// Input :
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output :
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    deque<long long> d;
    vector<long long> ans;

    int i;
    for (i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            d.push_back(i);
        }
    }
    if (d.size() == 0)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[d.front()]);
    }
    while (i < N)
    {
        if (!d.empty() && i - d.front() >= K)
        {
            d.pop_front();
        }
        if (A[i] < 0)
        {
            d.push_back(i);
        }
        if (d.size() == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[d.front()]);
        }
        i++;
    }
    return ans;
}
int main()
{
    long long i;
    long long int n;
    cin >> n;
    long long int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int k;
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
