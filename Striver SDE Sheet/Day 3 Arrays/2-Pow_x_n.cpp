

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
double myPow(double x, int n)
{
    long long nn = n;
    if (nn < 0)
        nn = -1 * nn;
    double ans = 1.0;
    while (nn)
    {
        if (nn % 2 == 1)
        {
            ans *= x;
            nn--;
        }
        else
        {
            x *= x;
            nn /= 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}
void solve()
{
    int x, n;
    cin >> x >> n;
    cout << myPow(x, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}