//We have given a number of stairs.We are at 0th stair and we need to reach nth stair
//constrains: Each time we can either climb one step or two step

#include<iostream>

using namespace std;

int count(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n<0)
    return 0;
    return count(n-1)+count(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<count(n);
    return 0;
}