#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int row = 1;
    int count = 1;
    while(row<=n)
    {
        int col = 1;
        while(col<=n-row)
        {
            cout<<" "<<" ";
            col++;
        }
        while(col<=n)
        {
            cout<<count<<" ";
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }
}