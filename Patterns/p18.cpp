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
        //For printing spaces
        while(col<=row-1)              //The spaces in every row are row-1;
        {
            cout<<" ";
            col++;
        }
        //For printing stars
        while(col<=n)
        {
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
}