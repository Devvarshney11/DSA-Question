#include <iostream>

using namespace std;

void spiralPrint(int matrix[4][4])
{
    int srow = 0;
    int scol = 0;
    int erow = 3;
    int ecol = 3;
    int count = 0;
    int total = 16;
    while (count < total)
    {
        for (int i = scol; count<total && i <= ecol; i++)
        {
            cout << matrix[srow][i] << " ";
            count++;
        }
        srow++;
        for (int i = srow; count<total && i <=erow; i++)
        {
            cout << matrix[i][ecol] << " ";
            count++;
        }
        ecol--;
        for (int i = ecol; count<total && i >= scol; i--)
        {
            cout << matrix[erow][i]<<" ";
            count++;
        }
        erow--;
        for (int i = erow ;count<total && i>= srow;i--)
        {
            cout<< matrix[i][scol]<<" ";
            count++;
        }
        scol++;
    }
}
int main()
{
    int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    spiralPrint(matrix);
    return 0;
}