#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
#define vin                    \
    for (ll i = 0; i < n; i++) \
    cin >> v[i]
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
int findMinimumCoins(int amount)
{
    vector<int> den = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int c = 0, i = 0;
    while (amount != 0)
    {
        if (amount >= den[i])
        {
            c++;
            cout<<den[i]<<" ";
            amount -= den[i];
        }
        else
            i++;
    }
    cout<<endl;
    return c;
}
void solve()
{
    int n;cin>>n;
    cout<<findMinimumCoins(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}