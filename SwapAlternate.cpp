#include<iostream>

using namespace std;
void swap(int &b, int &a)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapAlternate(int *arr,int n)
{
    for(int i = 0;i<n;i+=2)
    {
         if(i+1 == n)
         break;
         else
         {
            swap(arr[i],arr[i+1]);
         }
    }
}
int main()
{
     int arr[6] = {1,2,3,4,5,6};
     swapAlternate(arr,6);
     for(int i = 0;i<6;i++)
     {
        cout<<i[arr]<<" ";
     }
     return 0;
}