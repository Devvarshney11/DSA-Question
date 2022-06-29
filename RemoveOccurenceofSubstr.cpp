#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string allOccurence(string st, string part)
{
    while(st.length()>0 && st.find(part)<st.length())
    {
        st.erase(st.find(part),part.length());
    }
    return st;
}
int main()
{
    string st = "TheTheisTheis@The";
    cout<<allOccurence(st,"The");
    return 0;
}