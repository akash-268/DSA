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
bool check(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void solve(int id, string s, vector<string> ds, vector<vector<string>> &res)
{
    if (id == s.size())
    {
        res.push_back(ds);
        return;
    }
    for (int i = id; i < s.size(); i++)
    {
        if (check(s, id, i))
        {
            ds.push_back(s.substr(id, i - id + 1));
            solve(i + 1, s, ds, res);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> ds;
    solve(0, s, ds, res);
    return res;
}
void fun()
{
    string s;
    cin >> s;
    vector<vector<string>> res = partition(s);
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
        fun();
    }
}