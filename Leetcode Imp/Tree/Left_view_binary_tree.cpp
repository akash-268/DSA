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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void fun(TreeNode *root, int level, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    fun(root->left, level + 1, ans);
    fun(root->right, level + 1, ans);
}
vector<int> leftView(TreeNode *root)
{
    // Your code here
    vector<int> ans;
    fun(root, 0, ans);
    return ans;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}