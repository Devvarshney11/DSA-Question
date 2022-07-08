#include<iostream>

using namespace std;

int fibanocciNo(int n)
{
    if(n <= 1)
    return 0;
    if(n == 2)
    return 1;
    return fibanocciNo(n-1)+fibanocciNo(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fibanocciNo(n);
    return 0;
}