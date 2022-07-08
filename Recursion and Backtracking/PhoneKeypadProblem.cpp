// Given a string containing digits from 2 - 9 inclusive,
// return all possible letter combinations that the number could represent.
// Return the answer in any order.
// A mapping of digits to letters(just like on the telephone buttons)
// 0 -> ""
// 1 -> ""
// 2 -> "abc"
// 3 -> "def"
// 4 -> "ghi"
// 5 -> "jkl"
// 6 -> "mno"
// 7 -> "pqrs"
// 8 -> "tuv"
// 9 -> "wxyz"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
void solve(string digits,string op,int index,string mapping[],vector<string> &ans)
{
    if(index>=digits.length())
    {
        ans.push_back(op);
        return;
    }
    int num = digits[index] - '0';
    string value = mapping[num];
    for(int i = 0;i<value.size();i++)
    {
        op.push_back(value[i]);
        solve(digits,op,index+1,mapping,ans);
        op.pop_back(); //backtracking
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    string op = "";
    string mapping[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    int index = 0;
    solve(digits,op,index,mapping,ans);
    return ans;
}
int main()
{
    string str = "23";
    vector<string> ans = letterCombinations(str);
    for(auto it : ans)
    {
        cout<<it<<endl;
    }
    return 0;
}