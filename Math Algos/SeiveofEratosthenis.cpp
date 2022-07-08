//It is the Theorem for finding all prime numbers between the ranges 
//Eg : finding the  prime numbers betweem 1 to 10 : 2,3,5,7

#include<iostream>
#include<vector>

using namespace std;
vector<int> seiveOfEratosthenis(int n)
{
    vector<bool> isprime(n+1,true);
    vector<int> ans;
    isprime[0] = isprime[1] = false;
    for(int i = 2;i<=n;i++)
    {
        if(isprime[i])
        {
            ans.push_back(i);
            for(int j = 2*i;j<=n;j= j+i)
            {
                isprime[j] = false;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans = seiveOfEratosthenis(n);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    return 0;
}