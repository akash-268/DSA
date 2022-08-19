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
int pivotIndex(vector<int> &nums)
{
    vector<int> lsum(nums.size()), rsum(nums.size());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        lsum[i] = sum + nums[i];
        sum += nums[i];
    }
    sum = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        rsum[i] = sum + nums[i];
        sum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i] == rsum[i])
            return i;
    }
    return -1;
}
void solve()
{
    int n;
    cin >> n;
    vin v(n);
    f(i, 0, n) cin >> v[i];
    cout << pivotIndex(v);
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