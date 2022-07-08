// pivot index is the index where the sum of all the number strictly to the left
// of the index is equal to the sum of all the numbers strictly to the right
#include <iostream>

using namespace std;

int pivotIndex(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int temp = 0;
    for(int i = 0;i<n;i++)
    {
        sum -= arr[i];
        if(sum == temp)
        {
            return i;
        }
        temp += arr[i];
    }
    return -1;
}
int main()
{
    int n = 7;
    int arr[n] = {-1,1,2,3,3,-2,1};
    cout<<pivotIndex(arr,n);
    return 0;
}