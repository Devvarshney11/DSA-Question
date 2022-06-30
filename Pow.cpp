#include <iostream>

using namespace std;

// int pow(int a , int b)
// {
//     int ans = 1;
//     while(b>0)
//     {
//         if(b&1)
//         {
//             ans = ans * a;
//         }
//         a = a*a;
//         b = b>>1;
//     }
//     return ans;
// }
int pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ans = pow(a, b >> 1);
    if (b & 1)
        return a * ans * ans;
    else
        return ans * ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << pow(a, b);
    return 0;
}