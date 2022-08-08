#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> v;
    intervals.push_back({INT_MAX, INT_MAX});
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    int n = intervals.size();
    for (int i = 1; i < n; i++)
    {
        if (temp[1] >= intervals[i][0])
            temp[1] = max(temp[1], intervals[i][1]);
        else
        {
            v.push_back(temp);
            temp = intervals[i];
        }
    }
    return v;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> v[i][j];
    vector<vector<int>> ans = merge(v);
    for (auto it : ans)
        cout << "[" << it[0] << "," << it[1] << "] ";
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