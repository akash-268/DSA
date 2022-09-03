#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
#define ll long long int
vector<int> numsSameConsecDiff(int n, int k)
{
    vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 2; i <= n; ++i)
    {
        vector<int> cur2;
        for (int x : cur)
        {
            int y = x % 10;
            if (y + k < 10)
                cur2.push_back(x * 10 + y + k);
            if (k > 0 && y - k >= 0)
                cur2.push_back(x * 10 + y - k);
        }
        cur = cur2;
    }
    return cur;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> res = numsSameConsecDiff(n, k);
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