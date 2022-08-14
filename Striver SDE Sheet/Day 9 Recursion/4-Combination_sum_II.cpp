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
void solve(int id, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (sum == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = id; i < arr.size(); i++)
    {
        if (arr[i] > sum)
            break;
        if (i > id && arr[i] == arr[i - 1])
            continue;
        temp.push_back(arr[i]);
        solve(i + 1, sum - arr[i], arr, ans, temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, sum, arr, ans, temp);
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