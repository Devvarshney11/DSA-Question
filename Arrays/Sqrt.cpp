#include<iostream>

using namespace std;

int sqrt(int x)
{
    long long low = 0;
    long long high = 46340;
    int ans = -1;
    while(low<=high)
    {
        long long mid = low + (high-low)/2;
        if(mid*mid == x)
        {
           return mid;
        }
        if(mid * mid > x)
        {
            high = mid-1;
        }
        else if(mid*mid < x)
        {
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<sqrt(n);
    return 0;
}