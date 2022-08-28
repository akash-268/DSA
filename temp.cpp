#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV

void solve()
{
}

int main()
{
    auto b = make_shared<int>(25);
    cout << *b << endl;
    auto x = make_unique<int[]>(10);
    for (int i = 0; i < 10; i++)
    {
        x[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
        cout << x[i] << " ";
    return 0;
}