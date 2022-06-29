// You have given a string "str" of words.
// You need to replace all the spaces between words with "@40"

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
// string replaceSpaces(string &str){
// 	int n = str.length();
//     string temp = "";
//     for(int i = 0;i<n;i++)
//     {
//         if(str[i] == ' ')
//         {
//             temp +="@40";
//         }
//         else
//         {
//             temp +=str[i];
//         }
//     }
//     return temp;
// }
string replaceSpaces(string &str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            str = str.substr(0,i) + "@40" + str.substr(i+1,str.length()-1);
        }
        i++;
    }
    return str;
}
int main()
{
    string st = "Lion is the king Of jungle";
    st = replaceSpaces(st);
    cout<<st;
    return 0;
}