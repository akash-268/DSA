#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto it : mp)
        v.push_back(it.second);
    if (v.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    sort(v.begin(), v.end());
    if (v[v.size() - 1] > v[v.size() - 2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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