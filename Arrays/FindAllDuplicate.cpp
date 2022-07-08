#include<iostream>
#include<vector>

using namespace std;

vector<int> findDuplicates(vector<int>arr, int n)
{
    vector<int> count(n+1,0);
    vector<int> ans;
    for(int i = 0;i<n;i++)
    {
        count[arr[i]]++;
        if(count[arr[i]] == 2)
        {
            ans.push_back(arr[i]);
        }
    }  
    return ans;
}
int main()
{
    int n = 8;
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(7);
    vector<int> ans = findDuplicates(arr,n);
    for(int i: ans)
    {
        cout<<i<<" ";
    }
    return 0;
}