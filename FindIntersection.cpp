#include<iostream>
#include<vector>
using namespace std;

vector<int> find(vector<int>arr1,vector<int> arr2)
{ 
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            arr2[j] = -1;
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(3);
    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(3);
    vector<int> ans = find(arr1,arr2);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}