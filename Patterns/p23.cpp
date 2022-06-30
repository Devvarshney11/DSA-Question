#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int row = 1;
    while(row <= n)
    {
        int space = n-row;
        //print space
        while(space)
        {
            cout<<" "<<" ";
            space--;
        }
        //print 1st Triangle
        int col = 1;
        while(col <= row)
        {
            cout<<col<<" ";
            col++;
        }
        //print second triangle
        col = 1;
        while(col<= row-1)
        {
            cout<<row-col<<" ";
            col++;
        }
        row++;
        cout<<endl;
    }
}