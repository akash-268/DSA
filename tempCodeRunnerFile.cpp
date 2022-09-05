#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
void rec(vector<vector<int>> &v, int i, int j, int x, int y, int &c)
{
    if (i >= v.size() || j >= v[0].size())
        return;
    if (!(x == -1 || y == -1))
    {
        if (v[x][y] < v[i][j])
            c++;
        else
            return;
    }
    if (i < v.size())
        rec(v, i + 1, j, i, j, c);
    if (j < v[0].size())
        rec(v, i, j + 1, i, j, c);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rec(v, i, j, -1, -1, c);
    cout << c << endl;
}

int main()
{
    solve();
}