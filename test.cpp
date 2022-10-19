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
void fun(vector<pair<bool, ll>> &vec, ll &n, vector<ll> &v, ll &res)
{
    vec.pb({v[1], 1});
    for (ll i = 2; i < n; ++i)
        if (v[i] == vec[vec.size() - 1].fi)
            vec[vec.size() - 1].se++;
        else
            vec.pb({v[i], 1});
    vec.pb({0, 0});
    for (ll i = 0; i < vec.size() - 1; ++i)
        res += vec[i].se * (vec[i].se + 1) / 2;
    for (ll i = 0; i < vec.size() - 1; ++i)
        if (vec[i].fi)
            res += vec[i].se * vec[i + 1].se;
}
void solve()
{
    ll n, res;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    res = 0;
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    for (ll i = 1; i < n; ++i)
        b[i] = a[i] < a[i - 1];
    vector<pair<bool, ll>> vec;
    fun(vec, n, b, res);
    cout << res + n << endl;
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