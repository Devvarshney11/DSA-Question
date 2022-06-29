#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sum(vector<int> num1, vector<int> num2)
{
    int i = num1.size()-1;
    int j = num2.size()-1;
    vector<int> ans;
    int carry = 0;
    int sum = 0;
    while(i>=0 && j>=0)
    {
        sum = num1[i] + num2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i>=0)
    {
        sum = num1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0)
    {
        sum = num2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    while(carry)
    {
        sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> num1;
    num1.push_back(2);
    num1.push_back(0);
    vector<int> num2;
    num2.push_back(1);
    num2.push_back(0);
    num2.push_back(0);
    vector<int> ans = sum(num1,num2);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}