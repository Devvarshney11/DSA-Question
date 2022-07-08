// You are given a string s. Your task is to check wheter the string is palindrome or not.
// For checking palindrome, consider only alphabets and numbers ignore whitespace and symbols
// and the string is case sensitive

#include<iostream>
#include<cctype>

using namespace std;

bool check(string st)
{
    int start = 0;
    int end = st.length()-1;
    while(start<=end)
    {
        if(isalnum(st[start]) == 0)
        {
            start++;
        }
        if(isalnum(st[end]) == 0)
        {
            end--;
        }
        if(tolower(st[start]) != tolower(st[end]))
        return false;
        else
        {
            start++;
            end--;
        }
    }
    return true;
}
int main()
{
    string st = "Dev @ ved";
    cout<<check(st);
    return 0;
}
