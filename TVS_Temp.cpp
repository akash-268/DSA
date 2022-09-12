#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// JAI SHREE RAM
// HAR HAR MAHADEV
int solve(vector<int> v)
{
    int c = 0;
    for (auto it : v)
    {
        if (it > 0)
            c++;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    sort(a.begin(), a.end());
    int res = 0;
    int count = solve(a);
    if (count < m)
        res = -1;
    else
    {
        if (n > m)
            res = a[n - m - 1] > 0 ? a[n - m - 1] + 1 : 1;
        if (n == m)
            res = a[n - m] - 1;
    }
    if (res >= 1)
        cout << res;
    else
        cout << -1;
}