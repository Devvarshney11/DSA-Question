// We have to find the kth largest sum among all the subarray sums

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// Brute Force : By only Vector
// T.C. :- O(N^2logN)
// S.C. :- O(N^2)
int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sumStore;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size() - k];
}
// Optimize apparoach : By Minheap
// T.C. : O(N^2)
// S.C. : O(K)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main()
{
    return 0;
}