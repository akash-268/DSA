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
set<vector<int>> ans;
void solve(vector<int> arr, int i, vector<int> temp)
{
    if (i == arr.size())
    {
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
    }
    solve(arr, i + 1, temp);
    temp.push_back(arr[i]);
    solve(arr, i + 1, temp);
}    
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> temp;
    solve(nums, 0, temp);
    vector<vector<int>> res;
    for (auto it : ans)
    {
        res.push_back(it);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vin v(n);
    f(i, 0, n)
    {
        cin >> v[i];
    }
    vector<vector<int>> res = subsetsWithDup(v);
    for (auto it : res)
    {
        cout << "[";
        for (int i = 0; i < it.size(); i++)
        {
            if (i == it.size() - 1)
            {
                cout << it[i];
            }
            else
                cout << it[i] << ",";
        }
        cout << "] ";
    }
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
