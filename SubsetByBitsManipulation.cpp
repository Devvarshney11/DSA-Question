/*
If the length of nums is n there are pow(2,n) combinations/subsets in output
value varies from 0 to pow(2,n) - 1

Example - nums = [1,2,3] , Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
the  length of nums is 3 there are pow(2,3) -> 8 combinations/subsets in output
value varies from 0 to 8 - 1   -> 0  to 7

Decimal                Binary                    Subset
0         ->            000         ->            []
1         ->            001         ->            [1]
2         ->            010         ->            [2]
3         ->            011         ->            [1,2]
4         ->            100         ->            [3]
5         ->            101         ->            [1,3]
6         ->            110         ->            [2,3]
7         ->            111         ->            [1,2,3]

Time Complexity -> O(pow(2,n) * n)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); i++) // On left Shifting 1 n times we got 2^n
    {
        vector<int> op;
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & i)          // This condition of checking the bits means if
            {                          // i = 3 -> 010 -> {2}
                op.push_back(nums[j]); // we want to check that at which positon is 1
            }                          // we done it by left shifting 1 by j times and by doing and by i
            ans.push_back(op);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> ans = subsets(nums);
    return 0;
}