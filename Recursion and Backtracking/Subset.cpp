#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, ans);
    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subset(vector<int> nums)
{
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;
    solve(nums,output,index,ans);
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> ans = subset(nums);
     for(auto it: ans)
    {
        for(auto x : it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}