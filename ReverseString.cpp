#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
void reverse(string &s)
{
    int start = 0;
    int end = s.length()-1;
    while(start<=end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
int main()
{
    string s = "aabbccdd";
    reverse(s);
    cout<<s<<endl;
    return 0;
}