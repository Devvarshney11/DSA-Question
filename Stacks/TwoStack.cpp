// Design a data structure, which represents two stacks using only one array common for both stacks.

// The data structure should support the following operations:
// push1(NUM) - Push ‘NUM’ into stack1.
// push2(NUM) - Push ‘NUM’ into stack2.
// pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
// pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TwoStack
{
    int size;
    int top1;
    int top2;
    int *arr;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        size = s;
        arr = new int[s];
        top1 = -1;
        top2 = size;
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (top1 + 1 == top2 || top1 == size - 1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
            arr[++top1] = num;
        }
    }
    void push2(int num)
    {
        if (top2 - 1 == top1 || top2 == -1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
            arr[--top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 == -1)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top1--];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 == size)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top2++];
    }
};

int main()
{
    TwoStack st(5);
    st.push1(1);
    st.push2(5);
    st.push1(2);
    st.push2(4);
    st.push1(3);
    st.push2(6);
    return 0;
}
