#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

void setZeroes(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < row.size(); i++)
    {
        if (row[i] == 1)
        {
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < col.size(); i++)
    {
        if (col[i] == 1)
        {
            for (int j = 0; j < n; j++)
                a[j][i] = 0;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    setZeroes(v);
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << "-";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}