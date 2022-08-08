#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> v(numRows);
    for (int i = 0; i < numRows; ++i)
    {
        v[i] = vector<int>(i + 1);
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0 || j == i)
                v[i][j] = 1;
            else
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v = generate(n);
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
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