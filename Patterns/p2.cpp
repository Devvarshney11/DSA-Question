#include<iostream>
using namespace std;
int main()
{
    int count = 1;
    int n = 3;
    int i  = 1;
    while(i<=n)
    {
        int j = 1;
        while(j<=n)
        {
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}