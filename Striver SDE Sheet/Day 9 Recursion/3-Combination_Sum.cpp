#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
int solve(int n)
{
    int sum = 0;
    int root_n = (int)sqrt(n);
    for (int i = 1; i <= root_n; i++)
    {
        if (n % i == 0)
        {
            if (i == n / i && isPrime(i))
                sum += i;
            else
            {
                if (isPrime(i))
                    sum += i;
                if (isPrime(n / i))
                    sum += (n / i);
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);
}