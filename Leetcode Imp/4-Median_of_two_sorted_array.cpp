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
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n2 < n1)
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    int s = 0;
    int e = n1;
    int midInMergedArr = (n1 + n2 + 1) / 2;

    int cut1, cut2, l1, l2, r1, r2;

    while (s <= e)
    {
        cut1 = s + (e - s) / 2;
        cut2 = midInMergedArr - cut1;

        l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        r1 = (cut1 >= n1) ? INT_MAX : nums1[cut1];
        r2 = (cut2 >= n2) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
                return (max(l1, l2));
        }
        else if (r1 < l2)
        {
            s = cut1 + 1;
        }
        else if (r2 < l1)
        {
            e = cut1 - 1;
        }
    }
    return 0.0;
}
void solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin>>m;
    vector<int>b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cout << findMedianSortedArrays(v, b);
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