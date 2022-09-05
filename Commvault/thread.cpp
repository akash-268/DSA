#include <thread>
#include <iostream>
#include <unistd.h>
using namespace std;
void taskA()
{
    for (int i = 1; i <= 10; i++)
    {
        sleep(1);
        cout << "A:" << i << endl;
    }
}

void taskB()
{
    for (int i = 1; i <= 10; i++)
    {
        sleep(1);
        cout << "B:" << i << endl;
    }
}

int main()
{
    
    return 0;
}