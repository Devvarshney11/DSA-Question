#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

void deleteMiddle(stack<int> &st,int count,int n)
{
    if(count == n/2)
    {
        st.pop();
        return;
    }
    int ele = st.top();
    st.pop();
    deleteMiddle(st,count+1,n);
    st.push(ele);
}
void printStack(stack<int> st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    printStack(st);
    cout << ele << " ";
    st.push(ele);
}
int main()
{
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   deleteMiddle(st,0,5);
   printStack(st);
   return 0;
}