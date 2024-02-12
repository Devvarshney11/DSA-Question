#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Space Optimization
long long int solve(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    long long int a = 0;
    long long int b = nums[0];
    for (int i = 1; i < n; i++)
    {
        long long int rob = nums[i];
        if (i > 1)
            rob += a;
        long long int notrob = b;
        a = b;
        b = max(rob, notrob);
    }
    return b;
}
long long int houseRobber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    return max(solve(temp1), solve(temp2));
}

int main()
{
    return 0;
}