#include <iostream>

using namespace std;

void wavePrint(int matrix[3][3], int row, int col)
{
    int temp = 1;
    for (int i = 0; i < col; i++)
    {
        if (temp == 1)
        {
            for (int j = 0; j < row; j++)
            {
                cout << matrix[j][i] << " ";
            }
            temp = 0;
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                cout << matrix[j][i] << " ";
            }
            temp = 1;
        }
    }
}
int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    wavePrint(matrix,3,3);
    return 0;
}