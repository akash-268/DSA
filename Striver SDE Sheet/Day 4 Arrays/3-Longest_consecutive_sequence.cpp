#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// JAI SHREE RAM
// HAR HAR MAHADEV
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    vector<int> s;
    int c = 1, ans = 1;
    for (auto it : mp)
        s.push_back(it.first);
    for (auto it : s)
        cout << it << " ";
    if (s.size() == 1)
        return 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] - s[i - 1] == 1)
        {
            c++;
            ans = max(c, ans);
        }
        else
            c = 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << longestConsecutive(v);
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