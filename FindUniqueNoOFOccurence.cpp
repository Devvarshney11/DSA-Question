#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isUnique(vector<int> arr, int n)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            ans.push_back(count);
            count = 1;
        }
        if (i + 1 == n-1)
        {
            ans.push_back(count);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size()- 1; i++)
    {
        if (ans[i] == ans[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int n = 10;
    vector<int> arr(n);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    cout << isUnique(arr, n);
    return 0;
}