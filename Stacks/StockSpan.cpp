#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int *stockSpan(int *price, int n)
{
    stack<int> st;
    int *ans = new int[n];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && price[i] > price[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    int price[5] = {6,3,4,5,2};
    int *ans = stockSpan(price,5);
    for(int i = 0;i<5;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}