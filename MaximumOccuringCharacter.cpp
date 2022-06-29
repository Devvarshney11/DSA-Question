#include<iostream>

using namespace std;
char maxOccurChar(string st)
{
    int arr[26] = {0};
    for(int i = 0;i<st.length();i++)
    {
        int no;
        if(st[i]>='a' && st[i]<='z')
        {
             no = st[i] - 'a';
             arr[no]++;
        }
        else
        {
            no = st[i] - 'A';
            arr[no]++;
        }
    }
    int max = arr[0];
    int ans = 0;
    for(int i = 1;i<26;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            ans = i;
        }
    }
    return ans+'a';
}
int main()
{
     string st = "DEVvarshneye";
     cout<<maxOccurChar(st);
     return 0;    
}