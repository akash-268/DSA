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
bool isSafe(int row, int col, vector<string> &board)
{
    int r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }
    r = row, c = col;
    while (c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }
    r = row, c = col;
    while (r < board.size() && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }
    return true;
}
void solve(int id, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (id == n)
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, id, board))
        {
            board[i][id] = 'Q';
            solve(id + 1, board, ans, n);
            board[i][id] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> res = solveNQueens(n);
    for (auto it : res)
    {
        for (auto i : it)
        {
            cout << i << endl;
        }
        cout << "-------------------------" << endl;
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