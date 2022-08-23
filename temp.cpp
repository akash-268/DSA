#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
void check(vector<int> &v)
{
    int c = 0, i;
    for (i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
            c++;
    }
    cout << v.size() - c << " ";
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<pair<int, int>> c;
    for (i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        c.push_back(make_pair(x, y));
    }
    for (i = 0; i < c.size(); i++)
    {
        v[c[i].first - 1] = c[i].second;
        check(v);
    }
}

int main()
{
    solve();
    return 0;
}