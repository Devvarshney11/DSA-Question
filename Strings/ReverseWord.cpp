// We have to reverse each word separated by dot
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(string &st, int s, int e)
{
    while (s <= e)
    {
        swap(st[s], st[e]);
        s++;
        e--;
    }
}
void reverseWord(string &st)
{
    int s = 0;
    int e = 0;
    while(e<=st.length())
    {
        if(st[e] == '.' || st[e] == '\0')
        {
            reverse(st,s,e-1);
            s = e+1;
        }
        e++;
    }
}
int main()
{
    string s = "Dev.Varshney";
    reverseWord(s);
    cout<<s;
    return 0;
}