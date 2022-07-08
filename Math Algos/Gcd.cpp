//The no a and b . The max no which the factor of both a and b is called gcd of a and b.

#include<iostream>
#include<algorithm>

using namespace std;

// int gcd(int a, int b)
// {
//    if(a == b)
//    return a;
//    for(int i = 2;i<=min(a,b);i++)
//    {
//       if(a%i == 0 && b%i == 0)
//       {
//         return i;
//       }
//    }
//    return 1;
// }
int gcd(int a, int b)
{
    if(b == 0)
    return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}