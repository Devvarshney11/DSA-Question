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
        while(col<=n)
        {
            cout<<(char)(65+col-1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}