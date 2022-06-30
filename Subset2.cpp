// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

#include<bits/stdc++.h>

using namespace std;
void solve(vector<int> nums, vector<int> output, int index, set<vector<int>> &s)
{
    if (index == nums.size())
    {
        s.insert(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, s);
    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, s);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    int index = 0;
    vector<int> output;
    solve(nums, output, index, s);
    vector<vector<int>> ans;
    for (auto it : s)
    {
        ans.push_back(it);
    }
    return ans;
}
int main()
{
    return 0;
}