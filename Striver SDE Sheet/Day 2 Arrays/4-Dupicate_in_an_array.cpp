#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int findDuplicate(vector<int> &a)
{
    map<int, int> mp;
    for (auto it : a)
        mp[it]++;
    for (auto it : mp)
        if (it.second > 1)
            return it.first;
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << findDuplicate(v);
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