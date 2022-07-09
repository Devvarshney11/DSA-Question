#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
void removeAdjacent(string &str)
{
    int l = str.length();
    int i = 0;
    int stck = -1;
    while(i<l)
    {
        if(stck == -1 || str[stck] != str[i])
        {
            stck++;
            str[stck] = str[i];
            i++;
        }
        else
        {
            while(i<l && str[stck] == str[i])
            {
                i++;
                stck--;
            }
        }

    }
    string ans = "";
    for(int i = 0;i<=stck;i++)
    {
        ans.push_back(str[i]);
    }
    str = ans;
}
int main()
{
   string str = "devvar";
   removeAdjacent(str);
   cout<<str;                                                                                              
   return 0;
}