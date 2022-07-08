#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool find(int *arr,int n, int key)
{
    if(n == 0)
    return false;
    else if(n == 1)
    {
        return arr[0] == key;
    }
    if(arr[0] == key)
    {
         return true;
    }
    return find(arr+1,n-1,key);

}
int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<find(arr,5,1);
    return 0;
}