#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
#define f(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define vc vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int f0 = 0, f1 = 0;
    for (char c : s)
    {
        f0 += (c == '0');
        f1 += (c == '1');
    }
    if (f0 == 0)
    {
        cout << n << ' ' << 0 << endl;
        return;
    }
    if (f1 == 0)
    {
        cout << n << ' ' << 0 << endl;
        return;
    }
    cout << 1 << ' ' << abs(f0 - f1) + 1 << endl;
    for (int i = 0, Q = 0; i < abs(f0 - f1); ++i)
    {
        string t;
        for (int j = 0; j < (int)s.size() - 1; ++j)
            if ((s[j] == '0' && s[j + 1] == '1') || (s[j] == '1' && s[j + 1] == '0'))
            {
                Q = j;
                break;
            }
        cout << Q + 1 << ' ' << Q + 2 << ' ' << (f0 > f1) << endl;
        for (int j = 0; j < (int)s.size(); ++j)
            if (j != Q && j != Q + 1)
                t += s[j];
            else if (j == Q)
                t += char((f0 > f1) + 48);
        s = t;
    }
    cout << 1 << ' ' << s.size() << ' ' << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}