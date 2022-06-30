#include<iostream>
#include<algorithm>
using namespace std;
// void rotate(int matrix[3][3])
// {
//     //for transpose
//     for(int i = 0;i<3;i++)
//     {
//         for(int j = i;j<3;j++)
//         {
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }
//     //for reversing row
//     for(int i = 0;i<3;i++)
//     {
//         for(int j = 0;j<3/2;j++)
//         {
//             swap(matrix[i][j],matrix[i][3-1-j]);
//         }
//     }
// }
void rotate(int matrix[3][3])
{
    int n = 3;
    for(int i = 0 ;i<n/2;i++)
    {
        int start = i;
        int end = n-i-1;

        for(int j = start;j<end;j++)
        {
            int temp = matrix[start][j];
            matrix[start][j] = matrix[n-j-1][start];
            matrix[n-j-1][start] = matrix[end][n-j-1];
            matrix[end][n-j-1] = matrix[j][end];
            matrix[j][end] = temp;
        }
    }
}
int main()
{
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    rotate(matrix);
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}