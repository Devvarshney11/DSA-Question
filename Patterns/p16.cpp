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
        //For printing space
        while(col<=n-row)
        {
            cout<<" ";
            col++;
        }
        //for printing star
        while(col<=n)
        {
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
}