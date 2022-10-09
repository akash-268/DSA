#include <bits/stdc++.h>
using namespace std;

int check(int n)
{
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
        rev = rev * 10 + i % 10;
    return (n == rev);
}

int solve(int min, int max)
{
    int c = 0;
    for (int i = min; i <= max; i++)
        if (check(i) && i > 9)
        {
            c++;
        }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}