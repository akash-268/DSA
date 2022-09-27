#include <bits/stdc++.h>
using namespace std;

bool compareinterval(int i1[], int i2[])
{
    return (i1[0] < i2[0]);
}
int breakTime(int input1, int input2[])
{
    int i = 0, j = input1 - 1;
    int id1 = -1, id2 = -1;
    while (i < input1 - 1)
    {
        if (input2[i + 1] < input2[i])
        {
            id1 = i;
            break;
        }
        i++;
    }
    while (j >= 0)
    {
        if (input2[j - 1] > input2[j])
        {
            id2 = j;
            break;
        }
        j--;
    }
    cout << id1 << " " << id2 << endl;
    if (id1 != -1 and id2 != -1)
    {
        swap(input2[id1], input2[id2]);
    }
    int k = 1, sum = 0;
    for (int i = 0; i < input1; i++)
    {
        sum += input2[i] * k++;
    }
    return sum;
}

int main()
{
    int arr[5] = {3, 1, 6, 3, 1};
    cout << breakTime(5, arr);

    return 0;
}