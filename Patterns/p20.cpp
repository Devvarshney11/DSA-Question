#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int count = 1;
    int row = 1;
    while(row<=n)
    {
        int col = 1;
        //for printing spaces
        while(col<=n-row)
        {
            cout<<" "<<" ";
            col++;
        }
        //for printing number
        while(col<=n)
        {
            cout<<count<<" ";
            col++;
        }
        cout<<endl;
        count++;
        row++;
    }
}