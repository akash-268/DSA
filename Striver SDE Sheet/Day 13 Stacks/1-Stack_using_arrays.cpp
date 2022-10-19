#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack
{
    int n;
    int *arr;
    int tp;

public:
    Stack(int capacity)
    {
        // Write your code here.
        n = capacity;
        arr = new int[n];
        tp = -1;
    }

    void push(int num)
    {
        // Write your code here.
        if (!isFull())
        {
            tp++;
            arr[tp] = num;
        }
    }

    int pop()
    {
        // Write your code here.
        int x = -1;
        if (!isEmpty())
        {
            x = arr[tp];
            tp--;
        }
        return x;
    }

    int top()
    {
        // Write your code here.
        if (!isEmpty())
            return arr[tp];
        return -1;
    }

    int isEmpty()
    {
        // Write your code here.
        return tp == -1;
    }

    int isFull()
    {
        // Write your code here.
        return tp == n;
    }
};