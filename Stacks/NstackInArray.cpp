#include <iostream>

using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    int n;
    int s;
    int freespot;

public:
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        next = new int[s];
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Overflow Condtition
        if (freespot == -1)
        {
            return false;
        }
        // inititalize index;
        int index = freespot;

        // update freespot
        freespot = next[index];

        // push element in stack
        arr[index] = x;

        // update next;
        next[index] = top[m - 1];

        // update top;
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1;
        }
        int index = top[m - 1];
        int val = arr[index];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return val;
    }
};
int main()
{
    return 0;
}