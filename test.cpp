#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
#define vin vector<int>
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
const int maxi = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll eps = 1e-9;

void solve()
{
    ll n;
    cin >> n;
    if (n % 2)
    {
        for (int i = n - 3; i >= 2; i--)
            cout << i << " ";
        cout << n - 2 << " " << 1 << " " << n - 1 << " " << n << endl;
    }
    else
    {

        for (int i = n - 2; i >= 1; i--)
            cout << i << " ";
        cout << n - 1 << " " << n << endl;
    }
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