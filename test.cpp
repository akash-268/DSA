#include <iostream>
using namespace std;

class Work
{
    int number;
    static int counter;

public:
    Work()
    {
        number = counter;
        counter++;
        cout << "ok" << number << endl;
        if (number == 2)
        {
            throw 2;
        }
    }
};
int Work::counter = 1;
int main()
{
    try
    {
        Work array[3];
    }
    catch (int l)
    {
        for (int z = 1; z < 2; z++)
            cout << "dsdasda" << l << endl;
    }
}