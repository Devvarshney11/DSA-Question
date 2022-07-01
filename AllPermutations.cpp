#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void permutation(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permutation(nums, index + 1, ans);
        swap(nums[index], nums[i]); // backtrack
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    permutation(nums, 0, ans);
    return ans;
}
int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>> ans = permute(nums);
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