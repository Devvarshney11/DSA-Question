#include <bits/stdc++.h>

using namespace std;

int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    return -1;
}
void call_median(int element, priority_queue<int, vector<int>, greater<int>> &mini, priority_queue<int> &maxi, int &median)
{
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else
        {
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }
}
vector<int> findMedian(vector<int> &stream)
{
    int median = INT_MIN;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    vector<int> ans;
    for (int i = 0; i < stream.size(); i++)
    {
        call_median(stream[i], minHeap, maxHeap, median);
        ans.push_back(median);
    }
    return ans;
}
int main()
{
}