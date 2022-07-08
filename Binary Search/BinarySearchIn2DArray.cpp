// The 2D array is sorted in rows and first element of next row is greater than the last element of previous row
// ex:
// 1 2 3
// 4 5 6
// 7 8 9
#include<iostream>

using namespace std;

bool search(int matrix[][3] , int row , int col , int key)
{
    int low = 0;
    int high = row*col -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int r = mid/col;                           //The address of matrix[r][c] in memory is (col*r + c)
        int c = mid%col;
        if(matrix[r][c] == key)
        return true;
        else if(matrix[r][c]>key)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return false;
}
int main()
{
    int matrix[3][3] = {1,3,6,8,9,10,14,34,45};
    cout<<search(matrix,3,3,11);
    return 0;
}
