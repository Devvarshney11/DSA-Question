#include<iostream>

using namespace std;
string sayDigit(int n)
{
    if(n == 0)
    return "";
    int digit = n%10;
    n = n/10;
    string ans = "";
    switch(digit)
    {
        case 1 : ans += "one";
            break;
        case 2 : ans += "two";
            break;
        case 3 : ans += "three";
            break;
        case 4 : ans += "four";
            break;
        case 5 : ans += "five";
            break;
        case 6 : ans += "six";
            break;
        case 7 : ans += "seven";
            break;
        case 8 : ans += "eight";
            break;
        case 9 : ans += "nine";
            break;
        case 0 : ans += "zero";
            break;
    }
    return sayDigit(n)+" "+ans;
}
int main()
{
    int n;
    cin>>n;
    string ans = sayDigit(n);
    cout<<ans<<endl;
    return 0;
}