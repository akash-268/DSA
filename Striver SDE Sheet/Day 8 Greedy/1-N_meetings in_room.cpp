
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
static bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
vector<pair<int, int>> maxMeetings(vector<int> start, vector<int> end, int n)
{
    // Your code here
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(make_pair(start[i], end[i]));
    }
    sort(vec.begin(), vec.end(), cmp);
    int c = 1, endd = vec[0].second;
    vector<pair<int, int>> res;
    res.push_back(make_pair(vec[0].first, vec[0].second));
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first > endd)
        {
            c++;
            res.push_back(make_pair(vec[i].first, vec[i].second));
            endd = vec[i].second;
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> res = maxMeetings(a, b, n);
    cout << res.size();
    for (auto it : res)
    {
        cout << "(" << it.first << "," << it.second << ") ";
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