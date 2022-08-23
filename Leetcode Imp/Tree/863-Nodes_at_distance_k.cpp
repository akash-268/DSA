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
void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
{
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_track;
    markParents(root, parent_track, target);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        if (curr_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        result.push_back(current->val);
    }
    return result;
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