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
        //For printing spaces
        while(col<=row-1)              //The spaces in every row are row-1;
        {
            cout<<" "<<" ";
            col++;
        }
        //For printing numbers
        while(col<=n)
        {
            cout<<count<<" ";
            col++;
        }
        cout<<endl;
        row++;
        count++;
    }
}