#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int maxLen(vector<int> &a, int n)
{
    // Your code here
    int sum = 0;
    map<int, int> mp;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
                maxi = max(maxi, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxi;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<maxLen(v,n);
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