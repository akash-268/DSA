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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int p = 1, res = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            p++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            p--;
            j++;
        }
        res = max(res, p);
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    int a[n], b[n];
    f(i, 0, n) cin >> a[i];
    f(i, 0, n) cin >> b[i];
    cout << findPlatform(a, b, n);
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