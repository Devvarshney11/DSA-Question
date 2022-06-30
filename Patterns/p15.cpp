#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int row = 1;
    while(row<=n)
    {
        int col = 1;
        while(col<=row)
        {
            cout<<(char)((65+n-1)-(row-col+1)+1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}