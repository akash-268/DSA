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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res; // answer vector
    queue<TreeNode *> q;     // helper queue
    if (!root)
        return res;
    q.push(root);
    bool flag = true; // true matlab left tot right, false matlab right to left
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++) // size tak chalaya to get the level by level elements
        {
            TreeNode *node = q.front();
            q.pop();
            int id = flag ? i : size - 1 - i; // left to right store karna ya phir right to left using simple maths
            temp[id] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        flag = !flag;        // har level ke khatam hone pe flag ko revert karna (bohot important)
        res.push_back(temp); // har level ko push back karate gaye answer mein
    }
    return res;
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