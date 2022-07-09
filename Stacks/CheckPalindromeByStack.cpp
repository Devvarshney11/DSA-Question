#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool palindrome(string str)
{
     if(!(str.length()&1))
     {
        return false;
     }
     int i = 0;
     stack<char> st;
     while(str[i] != 'X')
     {
         st.push(str[i]);
         i++;
     }
     i++;
     while(str[i])
     {
         if(st.empty() || str[i] != st.top())
         {
            return false;
         }
         st.pop();
         i++;
     }
     return true;


}
int main()
{
    string str = "aabbccXcbbaa";
    cout<<palindrome(str);
    return 0;
}