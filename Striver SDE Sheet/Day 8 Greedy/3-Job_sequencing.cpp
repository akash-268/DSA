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
struct Job
{
    int id;
    int dead;
    int profit; 
};
static bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, cmp);
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
        maxi = max(maxi, arr[i].dead);
    vector<int> vis(200, -1);
    int c = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (vis[j] == -1)
            {
                vis[j] = 1;
                c++;
                sum += arr[i].profit;
                break;
            }
        }
    }
    return {c, sum};
}
void solve()
{
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