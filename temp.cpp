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
const int N = 1e5;
vector<int> tree[N];
int visited[N], baapu[N],
    children[N], check = -1;

void dfs(int curr, int papa)
{
    baapu[curr] = papa;
    for (int &child : tree[curr])
    {

        if (child == papa)
            return;
        dfs(child, curr);
    }

    if (visited[curr] == 1 && curr != 1)
    {

        children[curr] = 0;
        return;
    }

    int total_child = 0;
    for (auto &child : tree[curr])
    {
        if (child == papa)
            return;
        else
            ++total_child;
    }
    children[curr] = total_child;
    return;
}

int solve2(int n, int R)
{
    if (R > n)
    {
        check = 0;
        return 0;
    }
    int npr = 1;
    for (int i = n - R + 1; i <= n; ++i)
    {
        npr = npr * i;
    }
    return npr;
}

int NoOfWays(int Nodes, int colors)
{

    dfs(1, -1);
    int ways = 0;
    for (int i = 1; i <= Nodes; ++i)
    {
        if (i == 1)
        {
            ways = ways + colors *
                              solve2(colors - 1, children[1]);
        }
        else
        {
            if (visited[i] == 1)
            {
                continue;
            }
            else
            {
                ways = ways *
                       solve2(colors - 2, children[i]);
            }
        }
    }
    return ways;
}

void Tree(int n)
{
    while (n > 0)
    {
        int i, j;
        cin >> i >> j;
        tree[i].push_back(j);
        tree[j].push_back(i);
        visited[i]++, visited[j]++;
        n--;
    }
}
void solve()
{
    ll n, c;
    cin >> n >> c;
    Tree(n - 1);
    dfs(1, -1);
    ll ways = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            ways = ways + c *
                              solve2(c - 1, children[1]);
        }
        else
        {
            if (visited[i] == 1)
            {
                continue;
            }
            else
            {
                ways = ways *
                       solve2(c - 2, children[i]);
            }
        }
    }
    cout << ways << "\n";
}
int main()
{
    // Your code is here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}