#include<bits/stdc++.h>
using namespace std;
vector<int> primes;

void seive(int n)
{
   vector<int> isPrime(n+1,true);
   isPrime[0] = isPrime[1] = false;
   for(int i = 2;i<=n;i++)
   {
     if(isPrime[i])
     {
        for(int j =2*i;j<=n;j= j+i)
        {
            isPrime[j] = false;
        }
     }
   }
   for(int i = 2;i<=n;i++)
   {
    if(isPrime[i])
    {
        primes.push_back(i);
    }
   }
}
void segmentedseive(int l, int r, vector<int>&ans)
{
    vector<int> isPrime(r-l+1,true);
    for(int p : primes)
    {
        int s = l/p*p;
        if(s<l)
        {
            s += p;
        }
        for(int i = s ; i<=r ;i = i+p)
        {
           isPrime[i-l] = false;
        }
    }
    for(int i = 0;i<isPrime.size();i++)
    {
        if(isPrime[i])
        {
            ans.push_back(i+l);
        }
    }
}
int main()
{
    cout<<"Enter the value of n : ";
    int n;
    cin>>n;
    seive((int)floor(sqrt(n)));
    int update = floor(sqrt(n));
    vector<int> ans;
    for(int l = 2;l<n;l = l+update)
    {
        int r = min(l+update-1,n-1);
        segmentedseive(l,r,ans);
    }
    for(int x:primes)
    {
        cout<<x<<" ";
    }
    for(int x : ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;

}