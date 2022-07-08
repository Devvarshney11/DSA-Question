// The 2D array is sorted in rows and first element of next row is greater than the first element of previous row
// ex:
// 1 5 10
// 2 6 11
// 3 7 12

#include <iostream>

using namespace std;

bool search(int matrix[][3], int row, int col, int key)
{
    int i = 0;
    int j = col - 1;
    while (i<row && j>=0)
    {
        if (matrix[i][j] == key)
            return true;
        else if (matrix[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
int main()
{
    int matrix[3][3] = {1, 3, 6, 8, 9, 10, 14, 34, 45};
    cout << search(matrix, 3, 3, 14);
    return 0;
}