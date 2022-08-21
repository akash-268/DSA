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
vector<int> movesToStamp(string S, string T)
{
    if (S == T)
        return {0};
    int slen = S.size(), tlen = T.size() - slen + 1, i, j;
    vector<int> ans;
    bool tdiff = true, sdiff;
    while (tdiff)
        for (i = 0, tdiff = false; i < tlen; i++)
        {
            for (j = 0, sdiff = false; j < slen; j++)
                if (T[i + j] == '*')
                    continue;
                else if (T[i + j] != S[j])
                    break;
                else
                    sdiff = true;
            if (j == slen && sdiff)
            {
                for (j = i, tdiff = true; j < slen + i; j++)
                    T[j] = '*';
                ans.push_back(i);
            }
        }
    for (i = 0; i < T.size(); i++)
        if (T[i] != '*')
            return {};
    reverse(ans.begin(), ans.end());
    return ans;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> res = movesToStamp(s, t);
    for (auto it : res)
        cout << it << " ";
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