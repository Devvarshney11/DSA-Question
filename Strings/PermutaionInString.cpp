//Given two String s1 and s2 return true if s2 contains any permutaiton of s1 then return true;
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool isequal(int *count1 , int *count2)
{
    for(int i = 0;i<26;i++)
    {
        if(count1[i] != count2[i])
        return false;
    }
    return true;
}
bool isPermutaion(string s1, string s2)
{
    int count1[26] = {0};
    int index;
    for(int i = 0;i<s1.length();i++)
    {
        index = s1[i] - 'a';
        count1[index]++;
    }
    int w_size = s1.length();
    int count2[26] = {0};
    int i;
    for(i = 0;i<w_size && i<s2.length();i++)
    {
        index = s2[i]-'a';
        count2[index]++;
    }
    if(isequal(count1,count2))
    return true;
    for(;i<s2.length();i++)
    {
        index = s2[i] - 'a';
        count2[index]++;
        index = s2[i-w_size]-'a';
        count2[index]--;
        if(isequal(count1,count2))
        return true;
    }
    return false;
}

int main()
{
    string s1 = "abc";
    string s2 = "aabbcc";
    cout<<isPermutaion(s1,s2);
    return 0;
}