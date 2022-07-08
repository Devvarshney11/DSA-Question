// You are given an array 'ARR' of integers of length N.
// Your task is to find the next smaller element for each of the array elements.
// Next Smaller Element for an array element is the first element to the right of
// that element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    if (n == 0)
    {
        return ans;
    }
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[i] <= st.top())
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int>arr{2,1,4,3};
    vector<int> ans = nextSmallerElement(arr,4);
    for(int i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}