#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long> pq;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        pq.push(-1 * arr[i]);
    }
    while (pq.size() != 1)
    {
        long long a = -1 * pq.top();
        pq.pop();
        long long b = -1 * pq.top();
        pq.pop();
        long long sum = a + b;
        ans += sum;
        pq.push(-1 * sum);
    }
    return ans;
}
int main()
{
    return 0;
}