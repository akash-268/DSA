#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int fron, rear, size;

public:
    Queue()
    {
        // Implement the Constructor
        fron = 0;
        rear = 0;
        size = 100001;
        arr = new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (fron == rear)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
            cout << "FULL";
        else
            arr[rear++] = data;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (fron == rear)
            return -1;
        else
        {
            int a = arr[fron++];
            if (fron == rear)
            {
                fron = 0;
                rear = 0;
            }
            return a;
        }
    }

    int front()
    {
        // Implement the front() function
        if (!(fron == rear))
            return arr[fron];
        return -1;
    }
};

int main()
{
    return 0;
}