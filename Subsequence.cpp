#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void solve(string str, string op, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (op.length() > 0)
        {
            ans.push_back(op);
        }
        return;
    }
    // Exclude
    solve(str, op, index + 1, ans);
    // Include
    op += str[index];
    solve(str, op, index + 1, ans);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string op = "";
    int index = 0;
    solve(str, op, index, ans);
    return ans;
}

int main()
{
    string str= "abc";
    vector<string> ans = subsequences(str);
    for(auto it : ans)
    {
        cout<<it<<endl;
    }
    return 0;
}