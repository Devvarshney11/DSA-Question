#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string>subsequence(string str)
{
    int n = str.length();
    vector<string> ans;
    
    for(int i = 0;i<(1<<n);i++)
    {
        string op = "";
        for(int j = 0;j<n;j++)
        {
            if((1<<j)&i)
            {
                op += str[j];
            }
        }
        ans.push_back(op);
    }
    return ans;
}
int main()
{ 
    string str = "abc";
    vector<string> ans = subsequence(str);
    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    return 0;
}